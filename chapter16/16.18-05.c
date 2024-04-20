#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define LEN 30
#define PICK 6

void random_pick(int ar[], int length, int picks);

int main(void)
{
    int i, ch;
    int choices[LEN];

    for (i = 0; i < LEN; i++)
    {
        choices[i] = i + 1;
    }
    do
    {
        random_pick(choices, LEN, PICK);
        printf("Can you do again (y/n)? ");
        ch = getchar();
        while (getchar() != '\n')
            continue;
    } while ('y' == ch || 'Y' == ch);
    puts("Done.");

    return 0;
}

void random_pick(int ar[], int length, int picks)
{
    int count = 0;
    int i, br[length];

    memcpy(br, ar, length * sizeof(int));
    srand((unsigned int)time(0));
    printf("Pick %d numbers:\n", picks);
    while (picks > 0)
    {
        i = rand() % length;
        if (0 == br[i])
        {
            continue;
        }
        else
        {
            printf("%d ", br[i]);
            br[i] = 0;
            --picks;
        }
    }
    putchar('\n');
    return;
}
