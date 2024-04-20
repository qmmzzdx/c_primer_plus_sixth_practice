#include <stdio.h>

int main(void)
{
    char letters[26];

    printf("Here are 26 letters:\n");
    for (int i = 0; i < 26; ++i)
    {
        letters[i] = 'a' + i;
        printf("%c", letters[i]);
    }

    return 0;
}
