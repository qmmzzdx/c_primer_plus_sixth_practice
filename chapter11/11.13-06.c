#include <stdio.h>
#include <string.h>
#define LEN 20

char *s_gets(char *st, int n);
int is_within(char ch, const char *str);

int main(int argc, char *argv[])
{
    char ch, str[LEN];

    printf("Please enter a string (EOF to quit):\n");
    while (s_gets(str, LEN) != NULL)
    {
        printf("Please enter a character: ");
        ch = getchar();
        while (getchar() != '\n')
            continue;
        printf("String: %s\n", str);
        if (!is_within(ch, str))
        {
            printf("Not exist %c in the string.\n", ch);
        }
        else
        {
            printf("Exist %c in the string.\n", ch);
        }
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

int is_within(char ch, const char *str)
{
    while (*str)
    {
        if (*str == ch)
        {
            return 1;
        }
        ++str;
    }
    return 0;
}
