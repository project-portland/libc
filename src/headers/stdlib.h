/* * * * * * * * * * * * * * *
 * Portland libc stdlib.h    *
 * Copyright 2018 Benji Dial *
 * Under GNU GPL v3.0        *
 * * * * * * * * * * * * * * */

#ifndef __LIBC_STDLIB
#define __LIBC_STDLIB

typedef uint32_t size_t;
typedef /*TODO*/ wchar_t;
typedef struct {
  int q;
  int r;
} div_t;
typedef struct {
  long int q;
  long int r;
} ldiv_t;
typedef struct {
  long int q;
  long int r;
} lldiv_t;

#define NULL 0x00000000
#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0
#define RAND_MAX 0x7fffffff
#define MB_CUR_MAX /*TODO*/

double atof(const char *nptr);
int atoi(const char *nptr);
long int atol(const char *nptr);
long long int atoll(const char *nptr);
double strtod(const char *nptr, char **endptr);
float strtof(const char *nptr, char **endptr);
long double strtold(const char *nptr, char **endptr);
long int strtol(const char *nptr, char **endptr, int base);
long long int strtoll(const char *nptr, char **endptr, int base);
unsigned long int strtoul(const char *nptr, char **endptr, int base);
unsigned long long int strtoull(const char *nptr, char **endptr, int base);

int rand(void);
void srand(unsigned int seed);

void *calloc(size_t nmemb, size_t size);
void free(void *ptr);
void *realloc(void *ptr, size_t size);
void *malloc(size_t size);

void abort(void);
int atexit(void (*func)(void));
void exit(int status);
void _Exit(int status);
char *getenv(const char *name);
int system(const char *string);

void *bsearch(const void *key, const void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));

int abs(int j);
long int labs(long int j);
long long int llabs(long long int j);
div_t div(int numer, int denom);
ldiv_t ldiv(long int numer, long int denom);
lldiv_t lldiv(long long int numer, long long int denom);

int mblen(const char *s, size_t n);
int mbtowc(wchar_t *pwc, const char *s, size_t n);
int wctomb(char *s, wchar_t wc);
size_t mbstowcs(wchar_t *pwcs, const char *s, size_t n);
size_t wcstombs(char *s, const wchar_t *pwcs, size_t n);

#endif
