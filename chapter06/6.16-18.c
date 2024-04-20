#include <stdio.h>
#define DUNBAR_NUMBER 150

int main(void)
{
    int i = 1;
    int friends = 5;

    while (friends < DUNBAR_NUMBER)
    {
        printf("At %d weeks, Rabnud has", i);
        friends = 2 * (friends - i++);
        printf("%4d friends.\n", friends);
    }
    printf("At %d weeks, over Dunbar's number(%d).\n", i, DUNBAR_NUMBER);

    return 0;
}
