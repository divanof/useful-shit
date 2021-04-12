
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

struct hash_item {
	char *key;
	 int  key_len;

	struct hash_item *next;

	void *dptr;
};

struct hash_table {
	struct hash_item **buckets;
	int  nbuckets;
};

unsigned int hash(char *key, int len)
{
	unsigned int ret = 1;
	for (int i = 0; i < len; i++) {
		ret = ret * key[i] + 32;
	}

	return ret;
}

int hash_table_init(struct hash_table *, int nbuckets);
int hash_table_add(struct hash_table *, char *key, int len, void *dptr);
void *hash_table_find(struct hash_table *table, char *key, int len);
void  hash_table_print(struct hash_table *table);
/*
 * ADD key 12345
 * GET key
 */

int main()
{
	struct hash_table table = {0};
	int err;

	err = hash_table_init(&table, 2);
	if (err)
		return 1;

	while (1) {
		char mtd[4];

		scanf("%s", &mtd);
		
		if (mtd[0] == 'A' && mtd[1] == 'D' && mtd[2] == 'D') {
			char tmp[100];
			char *key;
			 int  key_len;
			 int  n;
			 int *num;
			 int  ret;

			scanf("%s", &tmp);

			key_len = strlen(tmp);
			key = malloc(key_len + 1);
			strcpy(key, tmp);
			key[key_len] = 0;
			ret = scanf("%d", &n);
			if (ret == 0) {
				printf("invalid num\n");
				continue;
			}

			num = malloc(sizeof(int));
			*num = n;

			hash_table_add(&table, key, key_len, num);
			continue;
		}

		if (mtd[0] == 'G' && mtd[1] == 'E' && mtd[2] == 'T') {
			char key[100];
			 int *num;

			scanf("%s", &key);

			num = hash_table_find(&table, key, strlen(key));
			if (NULL == num) {
				printf("Can't find value for key '%s'\n", key);
			} else {
				printf("for key '%s' value is %d\n", key, *num);
			}
		}

		if (mtd[0] = 'P' && mtd[1] == 'R' && mtd[2] == 'T') {
			hash_table_print(&table);
		}


	}

	return 0;
}

/*
 *#define NULL	(void *) 0
 */
int hash_table_init(struct hash_table *table, int nbuckets) {
	struct hash_item **buckets;

	buckets = calloc(nbuckets, sizeof(void *));
	if (NULL == buckets) {
		printf("%s() - malloc(): failed\n", __func__);
		return 1;
	}

	table->buckets = buckets;
	table->nbuckets = nbuckets;

	return 0;	
}

/* char *key [char* key] */
int hash_table_add(struct hash_table *table, char *key, int key_len, void *dptr) {
	unsigned int h;
	struct hash_item **item;

	h = hash(key, key_len) % table->nbuckets;

	item = &table->buckets[h];

	if (NULL == *item) {
		printf("%s() bucket[%d] is empty\n", __func__, h);
		goto __add;

	}
	
	while (*item) {
		printf("Buck[%d]: pass key '%s'\n", h, (*item)->key);
	
		if ((*item)->key_len != key_len) {
			item = &(*item)->next;
			continue;
		}

		int flag = 0;
		for (int i = 0; i < key_len; i++) {
			if ((*item)->key[i] != key[i]) {
				flag = 1;
				break;
			} else {
				continue;
			}
		}

		if (0 == flag) {
			printf("%s() - key exists\n", __func__);
			return 1;
		}

		item = &(*item)->next;
	}

	goto __add;

__add:
	(*item) = malloc(sizeof(struct hash_item));
	(*item)->key = key;
	(*item)->key_len = key_len;
	(*item)->next = NULL;
	(*item)->dptr = dptr;

	return 0;
}

void *hash_table_find(struct hash_table *table, char *key, int key_len) {
	
	unsigned int h;
	struct hash_item *item;

	h = hash(key, key_len) % table->nbuckets;

	item = table->buckets[h];

	if (NULL == item) {
		printf("%s() - bucket[%d] is NULL\n", __func__, h);
		return NULL;
	}

	while (item) {
		if (item->key_len != key_len) {
			item = item->next;
			continue;
		}

		for (int i = 0; i < key_len; i++) {
			if (item->key[i] != key[i]) {
				item = item->next;
				continue;
			}
		}

		return item->dptr;
	}

	return NULL;
}

void hash_table_print(struct hash_table *table) {
	struct hash_item *item;

	for (int i = 0; i < table->nbuckets; i++) {
		printf("Buck: %d\n", i);
		item = table->buckets[i];
		while (item) {
			printf("\t item: key: %s; value %d\n", item->key, *(int *) item->dptr);
			item = item->next;
		}
	}

	return;
}
