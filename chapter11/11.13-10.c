#include <stdio.h>
#include <string.h>
#define LEN 10

char *s_gets(char *st, int n);
void cancel(char *str);

int main(int argc, char *argv[])
{
    char str[LEN];

    printf("Please enter a string (EOF or enter to quit):\n");
    while (s_gets(str, LEN) != NULL && str[0] != '\0')
    {
        printf("Source string: %s\n", str);
        cancel(str);
        printf("Delete space: %s\n", str);
        printf("You can enter a string again (EOF or enter to quit):\n");
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

void cancel(char *str)
{
    int j = 0, len = strlen(str);
    
    for (int i = 0; i < len; ++i)
    {
        if (str[i] != ' ')
        {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}
