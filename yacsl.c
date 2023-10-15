#include"yacsl.h"

int sl_init(string_t* str, size_t len)
{
	if(str == NULL)
	{
		return SL_FAIL;
	}

	str->buffer = (char*)malloc(len*sizeof(char));
	if(str->buffer == NULL)
		return SL_FAIL;
	
	str->buffer[len-1] = '\0';
	str->len = len;	

	return SL_OK;
}
int sl_rep(string_t* str, char* val)
{
	if(str == NULL)
	{
		return SL_FAIL;
	}

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
int sl_repn(string_t* str, char* val, size_t n)
{
	if(str == NULL || 
	   val == NULL)
	{
		return SL_FAIL;
	}

	if(strlen(val)+n > str->len-1)
	{
		return SL_FAIL;
	}

	for(size_t i = 0;i<strlen(val);++i)
	{
		str->buffer[i+n] = val[i];
	}
	return SL_OK;
}
int sl_fill(string_t* str, char ch)
{
	if(str == NULL)
	{
		return SL_FAIL;
	}	
	
	for(size_t i = 0;i<str->len;++i)
	{
		str->buffer[i] = ch;
	}

	return SL_OK;	
}
int sl_filln(string_t* str, char ch, size_t n)
{
	if(str == NULL)
	{
		return SL_FAIL;
	}
	if(n > str->len-1)
	{
		return SL_FAIL;
	}

	for(size_t i = 0; i < str->len;++i)
	{
		str->buffer[i+n] = ch;
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

int sl_cat(string_t* a, string_t* b)
{
	if(a->buffer == NULL || 
	   b->buffer == NULL)
	{
		return SL_FAIL;
	}
	a->buffer = (char*)realloc(a->buffer,b->len*sizeof(char));

	if(a->buffer == NULL)
	{
		return SL_FAIL;
	}
	a->len = a->len + b->len;

	size_t n = 0;
	for(size_t i = a->len-1;i<a->len;++i,++n)
	{
		a->buffer[i]=b->buffer[n];
	}
	a->buffer[a->len-1] = '\0';
	
	return SL_OK;
}

int sl_slice(string_t* source, string_t* dest, size_t begin, size_t end)
{
	if(source == NULL ||
	   dest   == NULL)
	{
		return SL_FAIL;
	}	

	if(begin > source->len-1 ||
	   end   > source->len-1)
	{
		return SL_FAIL;
	}
	
	sl_free(dest);

	if(sl_init(dest,end-begin) != SL_OK)
	{
		return SL_FAIL;
	}

	size_t n = 0;
	for(size_t i = begin;i!=end;++i, ++n)
	{
		//printf("%c",source[i]);
		dest->buffer[n] = source->buffer[i];
	}

	return SL_OK;
}


