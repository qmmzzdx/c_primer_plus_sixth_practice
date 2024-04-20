#include <stdio.h>
#include <string.h>
#define N 15
#define LEN 30

struct names
{
    char fname[N];
    char mname[N];
    char lname[N];
};

struct messages
{
    char ins_num[LEN];
    struct names name;
};

char *s_gets(char *st, int n);
void show(const struct messages pt[], int n);

int main(void)
{
    int count = 0;
    struct messages m[5];

    printf("Please enter the insurance number:\n");
    printf("Press [enter] at the start of a line to stop.\n");
    while (count < 5 && s_gets(m[count].ins_num, LEN) && m[count].ins_num[0] != '\0')
    {
        printf("Now enter the former name.\n");
        s_gets(m[count].name.fname, N);
        printf("Now enter the middle name(Without, [enter] to the next).\n");
        s_gets(m[count].name.mname, N);
        printf("Now enter the last name.\n");
        s_gets(m[count].name.lname, N);
        if (count++ < 5)
        {
            printf("Enter the next insurance number:\n");
        }
    }
    if (count > 0)
    {
        show(m, count);
    }
    else
    {
        printf("No data!\n");
    }

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

void show(const struct messages pt[], int n)
{
    int i;

    printf("All numbers messages:\n");
    for (i = 0; i < n; i++)
    {
        if (pt[i].name.mname[0] == '\0')
        {
            printf("%s, %s", pt[i].name.fname, pt[i].name.lname);
            printf(" -- %s\n", pt[i].ins_num);
        }
        else
        {
            printf("%s, %s %c.", pt[i].name.fname, pt[i].name.lname, pt[i].name.mname[0]);
            printf(" -- %s\n", pt[i].ins_num);
        }
    }
    return;
}
