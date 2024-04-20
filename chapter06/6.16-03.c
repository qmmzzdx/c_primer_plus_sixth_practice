#include <stdio.h>

int main(void)
{
    for (int i = 1; i <= 6; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("%c", 'F' - j);
        }
        printf("\n");
    }

    return 0;
}
