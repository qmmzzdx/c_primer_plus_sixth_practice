#include <stdio.h>

int main(void)
{
    char ch;

    printf("Please enter a upper letter: ");
    scanf("%c", &ch);

    int length = ch - 'A';
    for (int i = 0; i <= length; i++)
    {
        char t = 'A' - 1;
        for (int j = 0; j < length - i; j++)
        {
            printf(" ");
        }
        for (int j = 0; j <= i; j++)
        {
            printf("%c", ++t);
        }
        for (int j = 0; j < i; j++)
        {
            printf("%c", --t);
        }
        printf("\n");
    }

    return 0;
}
