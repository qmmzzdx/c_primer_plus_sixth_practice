#include <stdio.h>
#define SECONDS_PER_YEAR 3.156e7

int main(void)
{
    double age;

    printf("Please enter your age: ");
    scanf("%lf", &age);
    printf("%g years old includes %g seconds.\n", age, age * SECONDS_PER_YEAR);

    return 0;
}
