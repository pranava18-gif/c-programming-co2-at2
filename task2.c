#include <stdio.h>

int calls = 0;

int verify(int card)
{
    calls++;
    return card;
}

int main()
{
    int senior, eligible, card, result;

    printf("Enter senior status (0/1): ");
    scanf("%d", &senior);

    printf("Enter eligible class (0/1): ");
    scanf("%d", &eligible);

    printf("Enter disability card (0/1): ");
    scanf("%d", &card);

    result = (senior && eligible) || verify(card);

    if (result)
        printf("Concession Granted");
    else
        printf("Concession Not Granted");

    printf("\nVerification Function Calls = %d", calls);

    calls = 0;

    if (0 && verify(1))
        printf("\nTrue");

    printf("\nCalls using && = %d", calls);

    calls = 0;

    if (0 & verify(1))
        printf("\nTrue");

    printf("\nCalls using & = %d", calls);

    return 0;
}
