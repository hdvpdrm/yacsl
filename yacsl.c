#include"yacsl.h"


void sl_init(string_t* str, size_t len)
{
	str->buffer = (char*)malloc(len*sizeof(char));
	str->buffer[len-1] = '\0';
	str->len = len;	
}
void sl_free(string_t* str)
{
	free(str->buffer);
	str->len = 0;
}
int sl_eq(string_t* a, string_t* b)
{
	return strcmp(a->buffer,b->buffer);
}
