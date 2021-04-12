
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "hash_table.h"

int main() {
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
