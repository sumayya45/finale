#include <stdio.h>
#include <stdlib.h>
int primenum(int i)
{
    for (int i = 0; i < 100; i++)
    {
        if (i % i == 0)
        {
            printf("the prime numbers are\n");
            printf("%d",i);
        }
    }
}
int main()
{
    printf("the primes from 1 to 100 are");
    primenum(1);
    return 0;
}