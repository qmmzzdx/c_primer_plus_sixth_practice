#include <stdio.h>
#define MASS_PER_MOLE 3.0e-23
#define MASS_PER_QUART 950

int main(void)
{
    double quart;

    printf("Please enter a quart for water: ");
    scanf("%lf", &quart);
    printf("%g quart water have %e water molecules.\n", quart, quart * MASS_PER_QUART / MASS_PER_MOLE);

    return 0;
}
