#include <stdio.h>
#include <ctype.h>
#define STOP '#'

int get_first(void);

int main(void)
{
    int ch;

    printf("Please enter some characters ('#' to quit):\n");
    while ((ch = get_first()) != STOP)
    {
        printf("Result: %c\n", ch);
        printf("You can enter again ('#' to quit):\n");
    }
    printf("Done.\n");

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
