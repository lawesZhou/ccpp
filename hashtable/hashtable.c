#include <stdlib.h>
#include <stdio.h>

#include "hashtable.h"

struct hash_list {
	const key_t key;
	value_t value;
	struct hash_list *next;	
};

struct hashtable {
	struct hash_list *slot[100];
};

struct hashtable *create_hashtable()
{
	struct hashtable *h = malloc(sizeof(struct hashtable));
	if (h == NULL)
		return NULL;

	int i;
	for (i = 0; i < 100; ++i)
		h->slot[i] = NULL;
	return h;
}

void destory_hashtable(struct hashtable *h)
{
	if (h == NULL)
		return;

	int i;
	for (i = 0; i < 100; ++i) {
		struct hash_list *l = h->slot[i];
		while (l) {
			struct hash_list *node = l;
			l = l->next;
			free(node);
		}
	}
	free(h);
}

static int hash_fun(const key_t key, int size)
{
	int sum = 0;
	int i;

	for(i = 0; key[i]; ++i)
		sum += key[i];
	return sum % size;
}

static int has_key(struct hash_list *l, const key_t key)
{
	while (l) {
		if (l->key == key)
			return 0;
		l = l->next;
	}
	return 1;
}

int insert_hashtable(struct hashtable *h, const key_t key, value_t value)
{
	struct hash_list *node = (struct hash_list *)
				 malloc(sizeof(struct hash_list));
	if (node == NULL)
		return -1;
	//find the slot number;
	int slot_no = hash_fun(key, 100);

	if (has_key(h->slot[slot_no], key)) {
		node->key = key;
		node->value = value;
		node->next = h->slot[slot_no];
		h->slot[slot_no] = node;	
	}
//	printf("&slot = %p\n", slot);
//	printf("&hslot = %p\n", h->slot[slot_no]);
//	traverse_hashtable(h);
	return 0;
}

void delete_hashtable(struct hashtable *h, const key_t key)
{
	if (find_hashtable(h, key, NULL))
		return;

	int slot_no = hash_fun(key, 100);

	struct hash_list *node = h->slot[slot_no]; 
	printf("&hslot = %p %p\n",h->slot[slot_no], node);
	printf("&hslot = %s\n",h->slot[slot_no]->key);
	if (node->key == key) {
		printf("&hslot = %p %p\n",h->slot[slot_no], node);
		struct hash_list *keynode = node;
		h->slot[slot_no] = keynode->next;
		free(keynode);
		return;
	}

	while (node) {
		if (node->next->key == key) {
			struct hash_list *keynode = node->next;
			node->next = node->next->next;
			free(keynode);
			return;
		}
		node = node->next;
	}

/*
	struct hash_list *slot = node->next;
	if (slot == NULL) {
		h->slot[slot_no] = NULL;
		free(node);
	}

	while (slot) {
		if (slot->key == key) {
			node->next = slot->next;
			free(slot);
			return;
		}
		node = slot;
		slot = slot->next;
	}	
*/
}

int find_hashtable(struct hashtable *h, const key_t key, value_t *value)
{
	if (h == NULL)
		return -1;

	int slot_no = hash_fun(key, 100);
	struct hash_list *slot = h->slot[slot_no];

	while(slot) {
		if (slot->key == key) {
			if (value)
				*value = slot->value;
			return 0;
		}
		slot = slot->next;
	}
	
	return -1;
}

void traverse_hashtable(struct hashtable *h)
{
	if (h == NULL)
		return;
	int i;
	for(i = 0; i < 100; ++i) {
		struct hash_list *l = h->slot[i];
		while(l) {
			printf("%s, %d\n", l->key, l->value);
			l = l->next;
		}
	}
}
