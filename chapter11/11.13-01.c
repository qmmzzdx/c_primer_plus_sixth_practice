#include <stdio.h>
#define LEN 10

void getnchar(char str[], int n);

int main(int argc, char *argv[])
{
    char str[LEN];

    printf("Please enter %d characters:\n", LEN - 1);
    getnchar(str, LEN);
    printf("Result:\n");
    puts(str);
    printf("Done.\n");

    return 0;
}

void getnchar(char str[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        str[i] = getchar();
    }
    str[n - 1] = '\0';
}
