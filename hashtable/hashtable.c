#include <stdlib.h>
#include <stdio.h>

#include "hashtable.h"

struct hash_list {
	const key_t key;
	value_t value;
	struct hash_list *next;	
};

struct hashtable {
	struct hash_list slot[100];
};

struct hashtable *create_hashtable()
{
	struct hashtable *h = malloc(sizeof(struct hashtable));
	if (h == NULL)
		return NULL;

	int i;
	for (i = 0; i < 100; ++i)
		h->slot[i].next = NULL;
	return h;
}

void destory_hashtable(struct hashtable *h)
{
	if (h == NULL)
		return;

	int i;
	for (i = 0; i < 100; ++i) {
		struct hash_list *node = h->slot[i].next;
		while (node) {
			struct hash_list *temp = node;
			node = node->next;
			free(temp);
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

static int has_key(struct hash_list *hlist, const key_t key)
{
	while (hlist) {
		if (hlist->key == key)
			return 0;
		hlist = hlist->next;
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

	if (has_key(h->slot[slot_no].next, key)) {
		node->key = key;
		node->value = value;
		node->next = h->slot[slot_no].next;
		h->slot[slot_no].next = node;	
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

	struct hash_list *node = &h->slot[slot_no]; 

	while (node) {
		if (node->next && node->next->key == key) {
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
	struct hash_list *slot = h->slot[slot_no].next;

	while (slot) {
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
	for (i = 0; i < 100; ++i) {
		struct hash_list *node = h->slot[i].next;
		while (node) {
			printf("%s, %d\n", node->key, node->value);
			node = node->next;
		}
	}
}
