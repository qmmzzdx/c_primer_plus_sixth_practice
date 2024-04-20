#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#define EPS 1e-6

int get_first(void);
int get_choice(void);
float get_float(void);

int main(void)
{
    int ct;
    float i, j;

    while ((ct = get_choice()) != 'q')
    {
        printf("Enter first number: ");
        i = get_float();
        printf("Enter second number: ");
        j = get_float();
        switch (ct)
        {
            case 'a':
            {
                printf("%g + %g = %g\n", i, j, i + j);
                break;
            }
            case 's':
            {
                printf("%g - %g = %g\n", i, j, i - j);
                break;
            }
            case 'm':
            {
                printf("%g * %g = %g\n", i, j, i * j);
                break;
            }
            case 'd':
            {
                while (fabs(j) <= EPS)
                {
                    printf("Enter a number other than 0: ");
                    j = get_float();
                }
                printf("%g / %g = %g\n", i, j, i / j);
                break;
            }
        }
    }
    printf("Bye.\n");

    return 0;
}

int get_first(void)
{
    int ch;

    do
    {
        ch = getchar();
    } while (isspace(ch));
    while (getchar() != '\n')
        continue;

    return ch;
}

int get_choice(void)
{
    int ch;

    printf("Enter the operation of your choice:\n");
    printf("a. add           s. subtract\n");
    printf("m. multiply      d. divide\n");
    printf("q. quit\n");
    
    ch = get_first();
    while (ch != 'a' && ch != 's' && ch != 'm' && ch != 'd' && ch != 'q')
    {
        printf("Please enter with a,s,m,d or q :");
        ch = get_first();
    }
    return ch;
}

float get_float(void)
{
    int ch;
    float input;

    while (scanf("%f", &input) != 1)
    {
        while ((ch = getchar()) != '\n')
        {
            putchar(ch);
        }
        printf(" is not an number.\n");
        printf("Please enter a number such as 2.5, -1.78E8 or 3: ");
    }
    return input;
}
