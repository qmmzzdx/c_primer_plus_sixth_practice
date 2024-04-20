#include <stdio.h>
#define PLAN1 17850
#define PLAN2 23900
#define PLAN3 29750
#define PLAN4 14875
#define RATE1 0.15
#define RATE2 0.28

void eatline(void);

int main(void)
{
    int n = 0;
    double wage, tax;

    while (1)
    {
        printf("********************************\n");
        printf("1) single\n");
        printf("2) householder\n");
        printf("3) married\n");
        printf("4) married but divorced\n");
        printf("5) quit\n");
        printf("********************************\n");
        printf("Please you choose: ");
        while (scanf("%d", &n) != 1 || (n > 5 || n < 1))
        {
            eatline();
            printf("Please enter 1, 2, 3, 4 or 5: ");
        }
        if (n == 5)
        {
            break;
        }
        printf("Please enter your wage: ");
        while (scanf("%lf", &wage) != 1 || (wage < 0))
        {
            eatline();
            printf("Please enter a number(>= 0): ");
        }
        eatline();
        switch (n)
        {
            case 1:
            {
                tax = (wage <= PLAN1 ? wage * RATE1 : PLAN1 * RATE1 + (wage - PLAN1) * RATE2);
                break;
            }
            case 2:
            {
                tax = (wage <= PLAN2 ? wage * RATE1 : PLAN2 * RATE1 + (wage - PLAN2) * RATE2);
                break;
            }
            case 3:
            {
                tax = (wage <= PLAN3 ? wage * RATE1 : PLAN3 * RATE1 + (wage - PLAN3) * RATE2);
                break;
            }
            case 4:
            {
                tax = (wage <= PLAN4 ? wage * RATE1 : PLAN4 * RATE1 + (wage - PLAN4) * RATE2);
                break;
            }
        }
        printf("Your tax: %g\n\n", tax);
    }
    printf("Done.\n");

    return 0;
}

void eatline()
{
    while (getchar() != '\n')
        continue;
}
