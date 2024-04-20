#include <stdio.h>
#include <string.h>
#define LEN 20

int main(void)
{
    char str[LEN];

    printf("Please enter a word: ");
    scanf("%19s", str);
    printf("The word is:\n");
    printf("%s\n", str);

    printf("Reversing the word is:\n");
    for (int i = strlen(str) - 1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }

    return 0;
}
