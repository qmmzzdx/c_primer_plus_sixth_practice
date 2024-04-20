#include <stdio.h>
#define SPACE_ASCII 32

int main(void)
{
    int ch, i = 0;

    printf("Please enter some characters:\n");
    while ((ch = getchar()) != EOF)
    {
        if (ch == '\n' || ch == '\t')
        {
            printf("'\\%c' - %d ", ch == '\n' ? (i = 0, 'n') : 't', ch);
        }
        else if (ch < SPACE_ASCII)
        {
            printf("'^%c' - %d ", ch + 64, ch);
        }
        else
        {
            printf("'%c' - %d ", ch, ch);
        }
        if (ch != '\n' && ++i % 10 == 0)
        {
            printf("\n");
        }
    }
    puts("Done.");

    return 0;
}
