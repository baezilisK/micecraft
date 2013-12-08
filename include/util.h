/*
 * Definition of useful macros, functions and constants.
 */
#ifndef UTIL_H
#define UTIL_H

#include <stdlib.h>

#define arrlen(u) (sizeof(u) / sizeof *(u))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define PI 3.14159265359 /* not defined by standard C89 */

/*
 * Allocates n bytes and returns a pointer to the memory.
 */
void *xmalloc (size_t n);

#endif /* UTIL_H */
