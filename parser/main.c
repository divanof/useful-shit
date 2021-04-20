
#include <stdio.h>

#include "json.h"

FILE *file = NULL;

int main()
{
	file = fopen("test.json", "r");

	struct json json;
	char buf[1024];
	int i = 0;
	int err;
	char c;

	while ((c = fgetc(file)) != EOF) {
		buf[i++] = c;
	}
	buf[i] = 0;

	err = json_init(&json, 32);
	if (err) {
		printf("can't init json\n");
		return 1;
	}

	err = json_decode(&json, buf, i);

	json_print(&json);	
	return 0;
}
