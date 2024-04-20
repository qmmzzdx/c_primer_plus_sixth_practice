#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int rollem(int sides);

int main(void)
{
    int dice, count, roll;
    int sides;
    int set, sets;

    srand((unsigned int)time(0));
    printf("Enter the number of sets.\nEnter q to stop: ");
    while (scanf("%d", &sets) == 1)
    {
        printf("How many sides and how many dice?\n");
        printf("Please two integers: ");
        if (scanf("%d %d", &sides, &dice) != 2)
        {
            puts("Not integers -- terminating input loop.");
            break;
        }
        printf("Here are %d sets of %d %d-sided throws.\n", sets, dice, sides);
        for (set = 0; set < sets; set++)
        {
            for (roll = 0, count = 0; count < dice; count++)
            {
                roll += rollem(sides);
            }
            printf("%-3d", roll);
            if (0 == (set + 1) % 8)
            {
                putchar('\n');
            }
        }
        printf("\nHow many sets? Enter q to stop: ");
    }
    puts("GOOD FORTUNE TO YOU!\n");

    return 0;
}

int rollem(int sides)
{
    return rand() % sides + 1;
}
