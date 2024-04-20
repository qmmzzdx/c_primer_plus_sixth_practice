#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN 10

char *s_gets(char *st, int n);
int myatoi(char *str);

int main(int argc, char *argv[])
{
    char str[LEN];

    printf("Please enter a string (EOF to quit):\n");
    while (s_gets(str, LEN) != NULL)
    {
        printf("String %s convert number %d\n", str, myatoi(str));
        printf("You can enter a string again (EOF to quit):\n");
    }
    printf("Done.\n");

    return 0;
}

char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;

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

int myatoi(char *str)
{
    int n = 0, len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        if (!isdigit(str[i]))
        {
            return 0;
        }
        n = n * 10 + (str[i] - '0');
    }
    return n;
}
