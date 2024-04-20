#include <stdio.h>
#define LEN 255

int main(void)
{
    int i = 0;
    char s[LEN];

    printf("Please enter a string:\n");
    while (scanf("%c", &s[i]) && i + 1 < LEN && s[i] != '\n')
    {
        ++i;
    }
    printf("Reversing print the string is:\n");
    for (i--; i >= 0; i--)
    {
        printf("%c", s[i]);
    }
    printf("\nDone.\n");

    return 0;
}
