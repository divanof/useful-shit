
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "hash_table.h"

#define DEBUG 0

unsigned int hash(char *key, int len)
{
        unsigned int ret = 1;
        for (int i = 0; i < len; i++) {
                ret = ret * key[i] + 32;
        }

        return ret;
}

int hash_table_init(struct hash_table *table, int nbuckets) {
        struct hash_item **buckets;

        buckets = calloc(nbuckets, sizeof(void *));
        if (NULL == buckets) {
#if DEBUG
                printf("%s() - malloc(): failed\n", __func__);
#endif
                return 1;
        }

        table->buckets = buckets;
        table->nbuckets = nbuckets;

        return 0;
}

int hash_table_add(struct hash_table *table, char *key, int key_len, void *dptr) {
        unsigned int h;
        struct hash_item **item;

        h = hash(key, key_len) % table->nbuckets;

        item = &table->buckets[h];

        if (NULL == *item) {
#if DEBUG
                printf("%s() bucket[%d] is empty\n", __func__, h);
#endif
	 	goto __add;
        }

        while (*item) {
#if DEBUG
                printf("Buck[%d]: pass key '%s'\n", h, (*item)->key);
#endif

                if ((*item)->key_len != key_len) {
                        item = &(*item)->next;
                        continue;
                }

                for (int i = 0; i < key_len; i++) {
                        if ((*item)->key[i] != key[i]) {
#if DEBUG
                                printf("%s() - hello!\n", __func__);
#endif
                                item = &(*item)->next;
                                break;
                        }
			
#if DEBUG
                        printf("%s() - key exists\n", __func__);
#endif
			return 1;
                }
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
#if DEBUG
                printf("%s() - bucket[%d] is NULL\n", __func__, h);
#endif		
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
