#include <stdio.h>

int main(void)
{
    double num;

    printf("Enter a float-point value: ");
    scanf("%lf", &num);
    printf("fixed-point notation: %f\n", num);
    printf("exponential notation: %e\n", num);
    printf("p notation: %a\n", num);

    return 0;
}
