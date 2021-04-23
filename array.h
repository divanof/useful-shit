
#ifndef ARRAY_H
#define ARRAY_H

struct array {
	void *items;
	 int nitems;
	 int capacity;
	 int item_size;
};

int array_init(struct array *arr, int capacity, int item_size);
struct array *array_new(int capacity, int item_size);

void *array_push(struct array *arr);
void *array_pop(struct array *arr);

static inline void *array_n(struct array *arr, int n)
{
	return n < arr->nitems ? arr->items + n * arr->item_size : NULL;
}

#endif
