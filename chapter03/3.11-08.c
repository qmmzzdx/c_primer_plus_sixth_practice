#include <stdio.h>
#define PINT_PER_CUP 2
#define CUP_PER_OUNCE 8
#define OUNCE_PER_BIGSPOON 2
#define BIGSPOON_PER_TEASPOON 3

int main(void)
{
    double pint, ounce, cup;
    double bigspoon, teaspoon;

    printf("Please you enter a number of cups: ");
    scanf("%lf", &cup);
    pint = cup / PINT_PER_CUP;
    ounce = cup * CUP_PER_OUNCE;
    bigspoon = ounce * OUNCE_PER_BIGSPOON;
    teaspoon = bigspoon * BIGSPOON_PER_TEASPOON;

    printf("Here are some ways to show %g cups:\n", cup);
    printf("Pint: %g\n", pint);
    printf("Ounce: %g\n", ounce);
    printf("Bigspoon: %g\n", bigspoon);
    printf("Teaspoon: %g\n", teaspoon);

    return 0;
}
