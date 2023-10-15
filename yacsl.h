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

//replace str's buffer with passed val from beginning
int sl_rep(string_t* str, char* val);

//replace str's buffer with passed val starting from nth element
int sl_repn(string_t* str, char* val, size_t n);

//fill str's buffer with passed character from bginning
int sl_fill(string_t* str, char ch);

//fill str's buffer with passed character starting from nth element
int sl_filln(string_t* str, char ch, size_t n);

//free str's buffer's memory
void sl_free(string_t* str);

//return 0 if a == b
int sl_eq(string_t* a, string_t* b);

//append a string to b string
int sl_cat(string_t* a, string_t* b);

//copies source[begin;end) to dest. dest will be overwritten
int sl_slice(string_t* source, string_t* dest, size_t begin, size_t end);

//returns the start position of character in str, -2 if not found, SL_FAIL if fails
int sl_findch(string_t* str, char ch);

//returns the start position of substring in str, -2 if not found, SL_FAIL if fails
int sl_findstr(string_t* str, string_t* sub);


#endif //YACSL_H
