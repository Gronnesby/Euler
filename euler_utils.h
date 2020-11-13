#ifndef __EULER_UTILS_H__
#define __EULER_UTILS_H__


// Primality test using 6k+-1 optimization.
int is_prime(long num);

// makes a file on disk of all primes smaller than limit
void generate_primes(unsigned int limit);

// reads a bunch of prime numbers from disk
void load_primes(unsigned int* count, unsigned int** buffer);

// recursive binary search in array of uints, returns T/F
unsigned int search(
    unsigned int *array, // search array
    unsigned int value,  // query value
    unsigned int start,  // should be first index in array (0)
    unsigned int end);   // should be last index in array

// sequential binary search in array of uints, see search()
unsigned int search_sequential(
    unsigned int *array, 
    unsigned int value, 
    unsigned int start,
    unsigned int end);

// Compare two strings, for use with qsort
int mystrcmp(const void *a, const void *b);

#endif
