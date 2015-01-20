#include <stdio.h>
#include "hashtable.h"

int
main()
{
	struct hashtable *hashtable = create_hashtable();
	const char *keys[] = {"hello", "world", "aabb", "bbaa"};
	int values[4] = {1, 2, 3, 4};

	int i;
	for (i = 0; i < 4; ++i) {
		if(insert_hashtable(hashtable, keys[i], values[i]) == 0)
			printf("insert key %s success\n", keys[i]);

	}
	traverse_hashtable(hashtable);

	int value1;
	if (find_hashtable(hashtable, "hello", &value1) == 0) 
		printf("find value of the key %s = %d\n", "hello", value1);
	delete_hashtable(hashtable, "hello");

	if (find_hashtable(hashtable, "hello", &value1) == 0) 
		printf("find value of the key %s = %d\n", "hello", value1);
	destory_hashtable(hashtable);
	return 0;
}
