#ifndef YACSL_H
#define YACSL_H
#define SL_FAIL -1
#define SL_OK   0

#include<string.h>
#include<stdlib.h>

typedef struct
{
	char* buffer;
	size_t len;
}string_t;


//init memory for str's buffer with passed len
int sl_init(string_t* str, size_t len);

//init str's buffer with passed val from beginning
int sl_fill(string_t* str, char* val);

//init str's buffer with passed val starting from nth element
int sl_filln(string_t* str, char* val, size_t n);

//free str's buffer's memory
void sl_free(string_t* str);

//return 0 if a == b
int sl_eq(string_t* a, string_t* b);

//append a string to b string
int sl_cat(string_t* a, string_t* b);


#endif //YACSL_H
