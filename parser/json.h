
#ifndef JSON_H
#define JSON_H

#include "numeric_types.h"
#include "hash_table.h"
#include "array.h"

enum {
	json_integer = 0,
	json_real,
	json_string,
	json_boolean,
	json_array,
	json_object,
	json_null,
};

struct json_string {
	u8 *loc;
	u32 len;
};

struct json_object {
	int type;

	union {
		int			 integer;
		double			 real;
		int			 boolean;
		struct array		 array;
		struct json_object	*object;
		struct json_string	 string;
		void			*null;
	} value;

	struct hash_table childs;
};

struct json {
	struct hash_table fields;
};

int json_init(struct json *json, u32 nbuckets);
int json_decode(struct json *json, u8 *buf, u32 len);
struct json_object *json_object_find(struct json *json, char *key, u32 key_len);

void json_print(struct json *json);

#endif
