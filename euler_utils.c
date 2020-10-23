
#include "euler_utils.h"
#include <string.h>

// Primality test using 6k+-1 optimization.
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