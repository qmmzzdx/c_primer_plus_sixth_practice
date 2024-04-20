#include <stdio.h>
#define STOP '#'

int main(void)
{
    int ch, n = 0;

    printf("Enter some characters('#' to quit):\n");
    while ((ch = getchar()) != STOP)
    {
        switch (ch)
        {
            case '.':
            {
                putchar('!');
                n++;
                break;
            }
            case '!':
            {
                printf("!!");
                n++;
                break;
            }
            default:
            {
                putchar(ch);
            }
        }
    }
    printf("\nTotal replace %d times.\n", n);
    printf("('.'->'!') or ('!'->'!!').\n");

    return 0;
}
