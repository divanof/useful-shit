
#include <stdio.h>
#include <stdlib.h>

#include "hash_table.h"

int main() {
	struct hash_table table = {0};
	int *num = malloc(sizeof(int));

	*num = 42;

	hash_table_init(&table, 8);

	hash_table_add(&table, "key", 3, num);
	hash_table_print(&table);
	return 0;
}
