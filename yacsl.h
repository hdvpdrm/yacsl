#ifndef YACSL_H
#define YACSL_H
#include<string.h>
#include<stdlib.h>

typedef struct
{
	char* buffer;
	size_t len;
}string_t;

void sl_init(string_t* str, size_t len);
void sl_free(string_t* str);
int sl_eq(string_t* a, string_t* b);


#endif //YACSL_H
