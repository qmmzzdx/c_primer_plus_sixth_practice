#include <stdio.h>
#include <string.h>
#define LEN 10

char *s_gets(char *st, int n);
void reverse(char *str);

int main(int argc, char *argv[])
{
    char str[LEN];

    printf("Please enter a string (EOF to quit):\n");
    while (s_gets(str, LEN) != NULL)
    {
        printf("String: %s\n", str);
        reverse(str);
        printf("After reversing: %s\n", str);
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

void reverse(char *str)
{
    int len = strlen(str);

    for (int i = 0, j = len - 1; i < j; i++, j--)
    {
        char temp = str[i];
        str[i] = str[j], str[j] = temp;
    }
}
