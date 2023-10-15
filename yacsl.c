#include"yacsl.h"

int sl_init(string_t* str, size_t len)
{
	str->buffer = (char*)malloc(len*sizeof(char));
	if(str->buffer == NULL)
		return SL_FAIL;
	
	str->buffer[len-1] = '\0';
	str->len = len;	

	return SL_OK;
}
int sl_fill(string_t* str, char* val)
{
	//decrement len, because strlen don't count the terminator null
	if(strlen(val) > str->len-1)
	{
		return SL_FAIL;
	}

	for(size_t i = 0;i<strlen(val);++i)
	{
		str->buffer[i] = val[i];
	}

	return SL_OK;
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
