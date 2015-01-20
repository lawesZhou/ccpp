#define key_t char *
typedef int value_t;

struct hashtable;

struct hashtable *create_hashtable();

void destory_hashtable(struct hashtable *h);

int insert_hashtable(struct hashtable *h, const key_t key, value_t value);

void delete_hashtable(struct hashtable *h, const key_t key);

int find_hashtable(struct hashtable *h, const key_t key, value_t *value);

void traverse_hashtable(struct hashtable *h);
