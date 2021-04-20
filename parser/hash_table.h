
#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdlib.h>

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

int hash_table_init(struct hash_table *, int nbuckets);
int hash_table_add(struct hash_table *, char *key, int len, void *dptr);
void *hash_table_find(struct hash_table *table, char *key, int len);
void  hash_table_print(struct hash_table *table);

unsigned int hash(char *key, int len);

#endif
