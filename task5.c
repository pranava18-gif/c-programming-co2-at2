#include <stdio.h>

unsigned long checks = 0;

int is_prime(unsigned long n)
{
    unsigned long i;

    checks = 0;

    if (n < 2)
        return 0;

    for (i = 2; i <= n / i; i++)
    {
        checks++;

        if (n % i == 0)
            return 0;
    }

    return 1;
}

int main()
{
    unsigned long tickets[] = {97, 100, 7919, 1000003};
    int i, result;

    for (i = 0; i < 4; i++)
    {
        result = is_prime(tickets[i]);

        printf("%lu %s divisions = %lu\n",
               tickets[i],
               result ? "prime" : "not prime",
               checks);
    }

    return 0;
}
