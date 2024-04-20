#include <stdio.h>

int main(void)
{
    int years = 0;
    double chuckie = 100.0;
    
    while (chuckie > 9)
    {
        ++years, chuckie += chuckie * 0.08, chuckie -= 10;
        printf("After %d years remains $%g.\n", years, chuckie);
    }
    printf("After %d years:\n", years + 1);
    printf("Chuckie has taken all of the money!\n");

    return 0;
}
