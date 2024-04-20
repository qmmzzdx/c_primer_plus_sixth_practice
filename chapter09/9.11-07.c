#include <stdio.h>
#include <ctype.h>

void attain_pos(void);
int position(int ch);

int main(void)
{
    attain_pos();

    return 0;
}

void attain_pos(void)
{
    int ch, figure;

    printf("Please enter a character (EOF to quit):\n");
    while ((ch = getchar()) != EOF)
    {
        figure = position(ch);
        if (figure != -1)
        {
            printf("%c is %d in alphabet.\n", ch, figure);
        }
        else
        {
            printf("%c isn't a letter.\n", ch); //包括回车换行符和空白符;
        }
        if (ch == '\n')
        {
            printf("You can enter again (EOF to quit): ");
        }
    }
    printf("Done.\n");
}

int position(int ch)
{
    return isupper(ch) ? ch - 'A' + 1 : (islower(ch) ? ch - 'a' + 1 : -1);
}
