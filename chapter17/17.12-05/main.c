#include <stdio.h>
#include <string.h>
#include "stack.h"
#define SLEN 81

char *s_gets(char *st, int n);

int main(void)
{
    int i;
    stack st;
    item ch, temp[SLEN];

    init(&st);
    printf("Please enter a string (EOF to quit):\n");
    while (s_gets(temp, SLEN) != NULL)
    {
        i = 0;
        while (temp[i] != '\0')
        {
            push(&st, temp[i++]);
        }
        printf("Reversing order:\n");
        while (!isempty(&st))
        {
            pop(&st, &ch);
            putchar(ch);
        }
        puts("\nYou can enter a string again (EOF to quit):");
    }
    puts("Done.");

    return 0;
}

char *s_gets(char *st, int n)
{
    char *find;
    char *ret_val;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
        {
            *find = '\0';
        }
        else
        {
            while (getchar() != '\n')
                continue;
        }
    }
    return ret_val;
}
