#include <stdio.h>

void cal_temperatures(double f_t);

int main(void)
{
    double temp;

    printf("Please enter a temperature number (q to quit): ");
    while (scanf("%lf", &temp) == 1)
    {
        cal_temperatures(temp);
        printf("You can enter again (q to quit): ");
    }
    printf("Done.\n");

    return 0;
}

void cal_temperatures(double f_t)
{
    const double f_val = 32.0;
    const double k_val = 273.16;
    double t = 5.0 / 9.0 * (f_t - f_val);
    printf("Centigrade temperature: %.2lf°C\n", t);
    printf("Fahrenheit temperature: %.2lf°C\n", f_t);
    printf("Kelvin temperature: %.2lf°C\n", t + k_val);
}
