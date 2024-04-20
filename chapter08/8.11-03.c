#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int ch;
    unsigned int uct = 0;
    unsigned int lct = 0;
    unsigned int oct = 0;

    printf("Please enter some characters:\n");
    while ((ch = getchar()) != EOF)
    {
        (isupper(ch) ? ++uct : islower(ch) ? ++lct : ++oct);
    }
    printf("Upper: %u\n", uct);
    printf("Lower: %u\n", lct);
    printf("Others: %u\n", oct);

    return 0;
}
