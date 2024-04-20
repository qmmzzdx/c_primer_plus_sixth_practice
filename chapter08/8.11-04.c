#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{
    bool inword = false;
    int ch, words = 0, letter = 0;

    printf("Please enter some words (EOF to quit):\n");
    while ((ch = getchar()) != EOF)
    {
        if (ispunct(ch))
        {
            continue;
        }
        if (isalpha(ch))
        {
            letter++;
        }
        if (!isspace(ch) && !inword)
        {
            inword = true;
            words++;
        }
        if (isspace(ch) && inword)
        {
            inword = false;
        }
    }
    double count = letter / words;
    printf("Total words: %d\n", words);
    printf("Total letters: %d\n", letter);
    printf("Average letters of words: %g\n", count);

    return 0;
}
