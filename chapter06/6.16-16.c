#include <stdio.h>

int main(void)
{
    int years = 0;
    double daphne = 100.0, deirdre = 100.0;

    while (deirdre <= daphne)
    {
        daphne += 0.10 * 100.0;
        deirdre += 0.05 * deirdre;
        ++years;
    }
    printf("Investment values after %d years:\n", years);
    printf("Daphne: $%.2f\n", daphne);
    printf("Deirdre: $%.2f\n", deirdre);
    printf("Deirdre(invest) > Daphne(invest)\n");

    return 0;
}
