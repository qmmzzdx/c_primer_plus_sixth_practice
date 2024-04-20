#include <stdio.h>

int main(void)
{
    int f_o, s_o;

    printf("This program computes moduli.\n");
    printf("Enter an integer to serve ");
    printf("as the second operand: ");
    scanf("%d", &s_o);
    printf("Now enter the first operand: ");
    while ((scanf("%d", &f_o) == 1) && (f_o > 0))
    {
        printf("%d %% %d is %d\n", f_o, s_o, f_o % s_o);
        printf("Enter next number for first operand (<= 0 to quit): ");
    }
    printf("Done\n");

    return 0;
}
