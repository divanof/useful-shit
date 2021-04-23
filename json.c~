
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "json.h"
#include "array.h"
#include "hash_table.h"
#include "numeric_types.h"
#include "parser_helper.h"

int json_init(struct json *json, u32 nbuckets)
{
	if (NULL == json)
		return 1;

	return hash_table_init(&json->fields, nbuckets);
}

enum {
	st_idle = 0,
	st_start,
	st_quote,
	st_quote_key,
	st_quote_key_quote,
};

int json_decode(struct json *json, u8 *buf, u32 len)
{
	u8 *p = buf;
	u8 *end = p + len;
	u8 *u, *v;

	int state = st_idle;

	while (p != end) {
		if (IS_DELIM(p)) {
			p++;
			continue;
		}

		switch (state) {
		case st_idle:
			if (IS_OPEN_BRACE(p)) {
				p++;
				state = st_start;
				break;
			}
			p++;
			break;

		case st_start:



		}
	}

	printf("%s(): buf: %s\n", __func__, (char *) buf);
	return 0;
}

void json_print(struct json *json)
{
	return;
}
