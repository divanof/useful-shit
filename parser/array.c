
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "array.h"

int array_init(struct array *arr, int capacity, int item_size)
{
	void *items;

	if (capacity < 0 || item_size < 0 || NULL == arr)
		return 1;

	items = malloc(capacity * item_size);
	if (NULL == items)
		return 1;

	arr->items = items;
	arr->nitems = 0;
	arr->capacity = capacity;
	arr->item_size = item_size;

	return 0;
}

struct array *array_new(int capacity, int item_size)
{
	struct array *arr;
	   int err;

	arr = malloc(sizeof(struct array));

	err = array_init(arr, capacity, item_size);
	if (err) {
		free(arr);
		return NULL;
	}

	return arr;
}

static int array_expand(struct array *arr)
{
	void *items;
	 int new_cap = arr->capacity << 1;

	items = realloc(arr->items, new_cap * arr->item_size);
	if (NULL == items)
		return 1;

	arr->items = items;
	arr->capacity = new_cap;

	return 0;
}

void *array_push(struct array *arr)
{
	void *item;
	 int err;

	if (arr->nitems == arr->capacity) {
		err = array_expand(arr);
		if (err) {
			return NULL;
		}
	}

	item = arr->items + arr->nitems * arr->item_size;
	arr->nitems++;

	return item;
}

void *array_pop(struct array *arr)
{
	if (0 == arr->nitems)
		return NULL;

	arr->nitems--;
	return arr->items + arr->nitems * arr->item_size;
}
