#include <stdio.h>

void cube(double c);

int main(void)
{
    double n;

    printf("Please you enter a double number: ");
    scanf("%lf", &n);
    cube(n);

    return 0;
}

void cube(double c)
{
    printf("The cube of %g is %g.\n", c, c * c * c);
}
