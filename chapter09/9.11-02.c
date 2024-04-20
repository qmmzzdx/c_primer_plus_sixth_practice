#include <stdio.h>
#define CHAR '#'

void chline(int ch, int cols, int rows);

int main(void)
{
    int i, j;

    printf("Please enter two numbers (q to quit): ");
    while (scanf("%d %d", &j, &i) == 2)
    {
        printf("Printing %c in %d rows and %d columns is:\n", CHAR, j, i);
        chline(CHAR, i, j);
        printf("You can enter two numbers again (q to quit): ");
    }
    printf("Done.\n");

    return 0;
}

void chline(int ch, int cols, int rows)
{
    int a, b;

    for (a = 1; a <= rows; a++)
    {
        for (b = 1; b <= cols; b++)
        {
            putchar(ch);
        }
        putchar('\n');
    }
    return;
}
