#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN 12

struct month
{
    char name[10];
    char abbrev[4];
    int days;
    int monumb;
};

const struct month months[LEN] = {
    {"January", "Jan", 31, 1},
    {"February", "Feb", 28, 2},
    {"March", "Mar", 31, 3},
    {"April", "Apr", 30, 4},
    {"May", "May", 31, 5},
    {"June", "Jun", 30, 6},
    {"July", "Jul", 31, 7},
    {"August", "Aug", 31, 8},
    {"September", "Sep", 30, 9},
    {"October", "Oct", 31, 10},
    {"November", "Nov", 30, 11},
    {"December", "Dec", 31, 12},
};

int days(char *name);

int main(void)
{
    int daytotal;
    char input[LEN];

    printf("Please enter the name of a month (q to quit): ");
    while (scanf("%11s", input) == 1 && input[0] != 'q')
    {
        daytotal = days(input);
        if (daytotal > 0)
        {
            printf("There are %d days through %s.\n", daytotal, input);
        }
        else
        {
            printf("%s isn't a valid month!\n", input);
        }
        printf("You can enter again (q to quit): ");
        while (getchar() != '\n')
            continue;
    }
    printf("Done.\n");

    return 0;
}

int days(char *name)
{
    int i = 1;
    int num = 0;
    int total = 0;

    name[0] = toupper(name[0]);
    while (name[i] != '\0')
    {
        name[i] = tolower(name[i]);
        i++;
    }
    for (i = 0; i < LEN; i++)
    {
        if (0 == strcmp(name, months[i].name))
        {
            num = months[i].monumb;
            break;
        }
    }
    if (num == 0)
    {
        total = -1;
    }
    else
    {
        for (i = 0; i < num; i++)
        {
            total += months[i].days;
        }
    }
    return total;
}
