# yacsl
yet another C strings library

### Usage
every functions returns SL_FAIL if something went wrong, so you should check the return value before<br>
doing anything else. Also it's safe, so you don't need to check your strings(if they are NULL pointers),<br>
because every function checks passed pointers.
### API
```c

#define SL_FAIL -1
#define SL_OK   0


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
int sl_findcstr(string_t* str, char* sub);

```
