#include <stdio.h>

unsigned long checks = 0;

int is_prime(unsigned long n)
{
    unsigned long i;

    checks = 0;

    if (n < 2)
        return 0;

    if (n == 2)
        return 1;

    if (n % 2 == 0)
    {
        checks++;
        return 0;
    }

    for (i = 3; i <= n / i; i += 2)
    {
        checks++;

        if (n % i == 0)
            return 0;
    }

    return 1;
}

int main()
{
    unsigned long numbers[] = {97, 100, 7919, 1000003};
    int i;

    for (i = 0; i < 4; i++)
    {
        if (is_prime(numbers[i]))
            printf("%lu is Prime", numbers[i]);
        else
            printf("%lu is Not Prime", numbers[i]);

        printf(" | Divisions = %lu\n", checks);
    }

    return 0;
}
