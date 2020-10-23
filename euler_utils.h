#ifndef __EULER_UTILS_H__
#define __EULER_UTILS_H__


// Primality test using 6k+-1 optimization.
int is_prime(long num);

// Compare two strings, for use with qsort
int mystrcmp(const void *a, const void *b);

#endif
