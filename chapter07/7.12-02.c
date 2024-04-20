#include <stdio.h>
#define STOP '#'

int main(void)
{
    int ch, i = 0;

    printf("Enter some characters('#' to quit):\n");
    while ((ch = getchar()) != STOP)
    {
        if (ch == '\n' || ch == '\t')
        {
            printf("'\\%c'- %d ", ch == '\n' ? (i = 0, 'n') : 't', ch);
        }
        else
        {
            printf("'%c'- %d ", ch, ch);
        }
        if (ch != '\n' && ++i % 8 == 0)
        {
            printf("\n");
        }
    }
    printf("Done.\n");

    return 0;
}
