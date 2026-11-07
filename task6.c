#include <stdio.h>

int main()
{
    float balance, rate, repayment;
    float interest, total_interest = 0;
    float payment;
    int month = 0;

    printf("Enter loan amount: ");
    scanf("%f", &balance);

    printf("Enter monthly interest rate: ");
    scanf("%f", &rate);

    printf("Enter monthly repayment: ");
    scanf("%f", &repayment);

    rate = rate / 100;

    if (balance <= 0 || rate < 0 || repayment <= 0)
    {
        printf("Invalid input");
        return 0;
    }

    if (repayment <= balance * rate)
    {
        printf("Loan cannot be repaid with this amount");
        return 0;
    }

    printf("\nMonth\tInterest\tPayment\tBalance\n");

    while (balance > 0.005 && month < 360)
    {
        month++;

        interest = balance * rate;

        total_interest += interest;

        balance = balance + interest;

        if (repayment < balance)
            payment = repayment;
        else
            payment = balance;

        balance = balance - payment;

        if (balance < 0.005)
            balance = 0;

        printf("%d\t%.2f\t\t%.2f\t%.2f\n",
               month, interest, payment, balance);
    }

    if (balance == 0)
    {
        printf("\nLoan Repaid in %d months", month);
        printf("\nTotal Interest = Rs. %.2f", total_interest);
    }
    else
    {
        printf("\nMaximum month limit reached");
    }

    return 0;
}
