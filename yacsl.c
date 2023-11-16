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
	//str is just a pointer to structure that contains another pointer
	//so both of them should not be NULL, otherwise this function fails to work
	//e.g. same idea works for every functions
	if(str == NULL ||
	   val == NULL)
	{
		return SL_FAIL;
	}
	
	if(str->buffer == NULL)
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
int sl_rrep(string_t* str, char* val)
{
	if(str == NULL ||
	   val == NULL)
	{
		return SL_FAIL;   
	}
	if(str->buffer == NULL)
	{
		return SL_FAIL;
	}
	for(size_t i = 0;i<str->len;++i)
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
	if(str->buffer == NULL)
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
	if(str->buffer == NULL)
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
	if(str->buffer == NULL)
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
	SL_FREE(str->buffer);
	str->len = 0;
}
void sl_free_arr(string_t** arr)
{
	size_t i = 0;
	while(arr[i] != NULL)
	{
		sl_free(arr[i]);
		++i;
	}	
	free(arr);
}
int sl_eq(string_t* a, string_t* b)
{
	return strcmp(a->buffer,b->buffer);
}

int sl_cat(string_t* a, string_t* b)
{
	if(a == NULL ||
	   b == NULL)
	{
	   	return SL_FAIL;
	}

	if(a->buffer == NULL || 
	   b->buffer == NULL)
	{
		return SL_FAIL;
	}
	
	a->buffer = (char*)realloc(a->buffer,b->len*sizeof(char));
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

	//don't check dest's buffer, because it will recreated
	if(source->buffer == NULL)
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
		dest->buffer[n] = source->buffer[i];
	}

	return SL_OK;
}

int sl_findch(string_t* str, char ch)
{
	if(str == NULL)
	{
		return SL_FAIL;
	}
	if(str->buffer == NULL)
	{
		return SL_FAIL;
	}

	char* found = strchr(str->buffer,ch);
	if(found == NULL) //no ch in str
	{
		return -2;
	}
	
	//return the position of character
	return found - str->buffer;	
}

int sl_findstr(string_t* str, string_t* sub)
{
	if(str == NULL ||
	   sub == NULL)
	{
	   	return SL_FAIL;
	}
	if(str->buffer == NULL ||
	   sub->buffer == NULL)
	{
		return SL_FAIL;
	}

	char* found = strstr(str->buffer,sub->buffer);
	if(found == NULL)
	{
		return -2; //no substring found
	}

	return found - str->buffer;
}
int sl_findcstr(string_t* str, char* sub)
{
	if(str == NULL ||
	   sub == NULL)
	{
		return SL_FAIL;
	}
	if(str->buffer == NULL)
	{
		return SL_FAIL;
	}

	char* found = strstr(str->buffer,sub);
	if(found == NULL)
	{
		return -2;
	}
	return found - str->buffer;
}

string_t** sl_split_by_size(string_t* str, size_t n, size_t* chunks_number)
{
	if(str == NULL || 
	   n == 0      )
	{
		return NULL;
	}
	if(str->buffer == NULL)
	{
		return NULL;
	}
	if(n > str->len)
	{
		return NULL;
	}

	//init just for one chunk
	string_t** chunks = (string_t**)malloc(sizeof(string_t*));
	if(chunks == NULL)
	{
		return NULL;
	}
	if(chunks_number)
	{
		*chunks_number = 1;
	}
	
	size_t current_chunk = 0;
	size_t i = 0;
	while(i<str->len)
	{
		if(current_chunk != 0)
		{ 
		  string_t** tmp= (string_t**)realloc(chunks, (current_chunk+1)*sizeof(string_t*));
		  if(tmp == NULL)
		    {
		      return NULL;
		    }
		 else
		    {
		     chunks = tmp;
		    }
			
	         if(chunks_number)
		   {
		    *chunks_number = current_chunk+1;
		   }
		}
	
		string_t* chunk = (string_t*)malloc(sizeof(string_t));
		if(chunk == NULL)
		{
			sl_free_arr(chunks);
			return NULL;
		}
		if(sl_init(chunk,n) != SL_OK)
		{
			sl_free_arr(chunks);
			return NULL;
		}
		
		for(size_t j = 0;j<n;++j)
		{
			chunk->buffer[j] = str->buffer[i];
			++i;	
		}

		chunks[current_chunk] = chunk;
		++current_chunk;
	}
	
	
	return chunks;
}

int sl_count(string_t* str, char ch)
{
	if(str == NULL)
	{
		return SL_FAIL;
	}
	if(str->buffer == NULL)
	{
		return SL_FAIL;
	}

	int count = 0;
	for(size_t i = 0;i<str->len;++i)
	{
		if(str->buffer[i] == ch)
		{
			++count;
		}
	}
	return count;
}

int sl_append(string_t* str, char ch)
{
	if(str == NULL)
	{
		return SL_FAIL;
	}
	if(str->buffer == NULL)
	{
		return SL_FAIL;
	}

	str->len+=1;
	str->buffer = (char*)realloc(str->buffer,(int)str->len*sizeof(char));
	str->buffer[str->len-1] = ch;
	return SL_OK;
}
