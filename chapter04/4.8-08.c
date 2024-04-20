#include <stdio.h>
#define GALLON_TO_LITRE 3.785
#define MILE_TO_KM 1.609

int main(void)
{
    double range, oil;

    printf("Please input the range you traveled(in mile): ");
    scanf("%lf", &range);
    printf("Please input the oil you spend(in gallon): ");
    scanf("%lf", &oil);

    printf("Fuel consumptions:\n");
    printf("In USA, your oil wear is %.1f mile / gallon.\n", range / oil);
    printf("In Europe, your oil wear is ");
    printf("%.1f litre / 100km.\n", 100.0 * (oil * GALLON_TO_LITRE) / (range * MILE_TO_KM));

    return 0;
}
