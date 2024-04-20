#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    int ch, lower, upper, digit;
    int punct, words;
    lower = upper = digit = 0;
    punct = words = 0;
    bool inword = false;

    printf("Please enter some characters (EOF to quit):\n");
    while ((ch = getchar()) != EOF)
    {
        if (islower(ch))
        {
            lower++;
        }
        else if (isupper(ch))
        {
            upper++;
        }
        else if (isdigit(ch))
        {
            digit++;
        }
        else if (ispunct(ch))
        {
            punct++;
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
    printf("Words: %d\n", words);
    printf("Lower: %d\n", lower);
    printf("Upper: %d\n", upper);
    printf("Digit: %d\n", digit);
    printf("Punct: %d\n", punct);

    return 0;
}
