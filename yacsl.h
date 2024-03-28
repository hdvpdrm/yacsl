#ifndef YACSL_H
#define YACSL_H

#define SL_FREE(x) if(x != NULL)free(x)

#define SL_FAIL 0
#define SL_OK   1

#include<stdlib.h>
#include<string.h>
#include<stdio.h>

typedef struct
{
	char* buffer;
	size_t len;
}string_t;


//*******************STRING CREATION FUNCTIONS****************************//

//init memory for str's buffer with passed len and end line with \0
int sl_init(string_t* str, size_t len);

//copy source to destination.
int sl_copy(string_t* source, string_t* destination);

//free str's buffer's memory
void sl_free(string_t* str);

//free array made of strings
void sl_free_arr(string_t** arr);

///////////////////////////////////////////////////////////////////////////


//*******************STRING REPLACEMENT FUNCTIONS*************************//

//replace str's buffer with passed val from beginning
int sl_rep(string_t* str, char* val);

//replace str's buffer with passed val and kill terminating null
int sl_rrep(string_t* str, char* val);

//replace str's buffer with passed val starting from nth element
int sl_repn(string_t* str, char* val, size_t n);

//fill str's buffer with passed character from bginning
int sl_fill(string_t* str, char ch);

//fill str's buffer with passed character starting from nth element
int sl_filln(string_t* str, char ch, size_t n);

//replace a char from str with b char
int sl_replace_all(string_t* str, char a, char b);

///////////////////////////////////////////////////////////////////////////


//*******************STRING ACCUMULATION FUNCTIONS*************************//

//append a string to b string
int sl_cat(string_t* a, string_t* b);

//append character to the end of str
int sl_append(string_t* str, char ch);

///////////////////////////////////////////////////////////////////////////

//*******************STRING SLICING FUNCTIONS*************************//

//copies source[begin;end) to dest. dest will be overwritten
int sl_slice(string_t* source, string_t* dest, size_t begin, size_t end);

//split string by size into array of equal chunks. Returns NULL if fails
string_t** sl_split_by_size(string_t* str, size_t n, size_t* chunks_number);

///////////////////////////////////////////////////////////////////////////

//*******************LOGICAL-ARITHMETIC FUNCTIONS*************************//

//RETURNS the start position of character in str, -2 if not found, SL_FAIL if fails
int sl_findch(string_t* str, char ch);

//returns the start position of substring in str, -2 if not found, SL_FAIL if fails
int sl_findstr(string_t* str, string_t* sub);
int sl_findcstr(string_t* str, char* sub);

//return number of counter characters or  SL_FAIL
int sl_count(string_t* str, char ch);

//return 0 if a == b
int sl_eq(string_t* a, string_t* b);

///////////////////////////////////////////////////////////////////////////
#endif //YACSL_H
