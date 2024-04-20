#include <stdio.h>
#define CM_PER_INCH 2.54

int main(void)
{
    double inch;

    printf("Please enter your height(inch): ");
    scanf("%lf", &inch);
    printf("Your height is %g cm.\n", inch * CM_PER_INCH);

    return 0;
}
