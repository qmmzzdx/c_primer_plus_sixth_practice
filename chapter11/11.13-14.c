#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int exp;
    double num, sum = 1.0;

    if (argc != 3)
    {
        printf("Usage: %s floating-point exp\n", argv[0]);
    }
    else
    {
        num = atof(argv[1]), exp = atoi(argv[2]);
        for (int i = 1; i <= exp; i++)
        {
            sum *= num;
        }
        printf("%g ^ %d is %g.\n", num, exp, sum);
    }

    return 0;
}
