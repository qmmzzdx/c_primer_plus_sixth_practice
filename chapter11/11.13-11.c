#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#define ROWS 10
#define COLUMNS 10

int get_strings(char (*string)[COLUMNS], char **str, int n);
int get_first(void);
int show_menu(void);
int word(char *str);
char *s_gets(char *st, int n);
void print_original_strings(char (*string)[COLUMNS], int n);
void print_strings(char **str, int n);
void sort_strings(char **str, char ch, int n);
bool check(char *s1, char *s2, char ch);

int main(void)
{
    int n, choice;
    char *str[ROWS];
    char strings[ROWS][COLUMNS];

    printf("Please enter %d strings (EOF to quit):\n", ROWS);
    if ((n = get_strings(strings, str, ROWS)) != 0)
    {
        while ((choice = show_menu()) != 'q')
        {
            if (choice == 'a')
            {
                print_original_strings(strings, n);
            }
            else
            {
                sort_strings(str, choice, n);
                print_strings(str, n);
            }
        }
    }
    printf("Done.\n");

    return 0;
}

int get_strings(char (*string)[COLUMNS], char **str, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (s_gets(string[i], COLUMNS) != NULL)
        {
            str[i] = string[i];
        }
        else
        {
            break;
        }
    }
    return i;
}

int get_first(void)
{
    int ch;

    do
    {
        ch = tolower(getchar());
    } while (isspace(ch));
    while (getchar() != '\n')
        continue;

    return ch;
}

int show_menu(void)
{
    int ch;

    printf("+-------------------------------------------------------+\n");
    printf("|a) print for the origin          b) print for the ASCII|\n");
    printf("|c) print for the length          d) print for the words|\n");
    printf("|q) quit                                                |\n");
    printf("+-------------------------------------------------------+\n");
    printf("Please you choose: ");
    
    ch = get_first();
    while (ch < 'a' || ch > 'd' && ch != 'q')
    {
        printf("Please enter a, b, c, d or q: ");
        ch = get_first();
    }
    return ch;
}

int word(char *str)
{
    int length = 0;
    bool inword = false;

    /*统计字符串第一个非空白字符的单词
    长度并作为返回值传递给调用函数;*/
    while (*str)
    {
        if (!isspace(*str) && !inword)
        {
            /*↑从第一个非空白字符
            开始统计单词长度*/
            inword = true;
            length++;
        }
        else if (!isspace(*str) && inword)
        {
            length++;
        }
        else if (isspace(*str) && inword)
        {
            /*↑若遇到第一个单词后的空白符
            则退出循环*/
            break;
        }
        str++;
    }
    return length;
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

void print_original_strings(char (*string)[COLUMNS], int n)
{
    printf("Source strings:\n");
    for (int i = 0; i < n; i++)
    {
        puts(string[i]);
    }
    putchar('\n');
}

void print_strings(char **str, int n)
{
    printf("Target strings:\n");
    for (int i = 0; i < n; i++)
    {
        puts(str[i]);
    }
    putchar('\n');
}

void sort_strings(char **str, char ch, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (check(str[i], str[j], ch))
            {
                char *temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

bool check(char *s1, char *s2, char ch)
{
    return ch == 'b' ? strcmp(s1, s2) > 0 : (ch == 'c' ? strlen(s1) > strlen(s2) : word(s1) > word(s2));
}
