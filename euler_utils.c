#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "euler_utils.h"


unsigned int search(
    unsigned int *array, 
    unsigned int value, 
    unsigned int start,
    unsigned int end) 
{
    // stop condition!
    if (start == end) {
        return value == array[start];
    }

    // split array in two
    int middle = (end - start)/2 + start;
    if (value > array[middle]) {
        return search(array, value, middle + 1, end);
    } else {
        return search(array, value, start, middle);
    }
}

unsigned int search_sequential(
    unsigned int *array, 
    unsigned int value, 
    unsigned int start,
    unsigned int end) 
{
    int middle;

    while (start != end) { // stop condition

        // split array in two
        middle = (end - start)/2 + start;
        if (value > array[middle]) {
            start = middle + 1;
        } else {
            end = middle;
        }
    }

    return array[end] == value;
}

void generate_primes(unsigned int limit) {
    // allocate space for our primes
    unsigned int num_primes = 1.4*limit/log(limit);  // approximate prime counting function 
    unsigned int* prime_array = malloc(num_primes * sizeof(unsigned int));    
    
    // checks all numbers from 2 to limit
    // work can be cut in half by a simple modification (exercise for the reader)
    unsigned int prime_count = 0;
    for (unsigned int i = 2; i <= limit; i++) {
        if (is_prime(i)) prime_array[prime_count++] = i;

        if (!(prime_count < num_primes)) { printf("Array too small\n"); exit(-1); }

        // progress counter updates every 10k 
        if ((i % 10000) == 0) printf("\r%d %%       ", (int)((100*(float) i)/(float)limit));
    }

    // write to file
    FILE* fpt;
    fpt = fopen("primes.bin", "wb");

    fwrite(&prime_count, sizeof(unsigned int), 1, fpt);  // writes array size
    fwrite(prime_array, sizeof(unsigned int), prime_count, fpt); // writes data

    fclose(fpt);

    printf("\r wrote %d primes to primes.bin\n", prime_count);
}

void load_primes(unsigned int* count, unsigned int** buffer) {
    FILE* fpt;
    fpt = fopen("primes.bin", "rb");

    // first read array size
    fread(count, sizeof(unsigned int), 1, fpt);

    // allocate space, read data into array
    *buffer = malloc((* count)*sizeof(unsigned int));
    fread(*buffer, sizeof(unsigned int), *count, fpt);

    printf("read %d primes from primes.bin\n", *count);

    fclose(fpt);
}

int is_prime(long num)
{

    if (num <= 3)
    {
        return num > 1;
    }
    else if (((num % 2) == 0) || ((num % 3) == 0))
    {
        return 0;
    }
    
    for (long i = 5; (i * i) <= num; i += 6)
    {
        if (((num % i) == 0) || ((num % (i + 2)) == 0))
        {
            return 0;
        }
    } 
    return 1;
}


int mystrcmp(const void *a, const void *b)
{
    int cmp =  strcmp(*(const char **)a, *(const char **)b);

    if (cmp < 0)
    {
        return -1;
    }
    else if (cmp > 0)
    {
        return 1;
    } 
    else 
    {
        return 0;
    }
}