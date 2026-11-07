#include <stdio.h>

int main()
{
    float price, qty, gross, discount, tax, total, net;
    int senior;

    printf("Enter price: ");
    scanf("%f", &price);

    printf("Enter quantity: ");
    scanf("%f", &qty);

    printf("Senior citizen (1-Yes, 0-No): ");
    scanf("%d", &senior);

    gross = price * qty;

    if (senior == 1)
        discount = gross * 15 / 100;
    else
        discount = 0;

    tax = (gross - discount) * 5 / 100;

    total = gross - discount + tax;

    if (total > 1000)
        net = total - 50;
    else
        net = total;

    printf("\nGross Amount = %.2f", gross);
    printf("\nDiscount = %.2f", discount);
    printf("\nGST = %.2f", tax);
    printf("\nTotal = %.2f", total);
    printf("\nNet Amount = %.2f", net);

    return 0;
}
