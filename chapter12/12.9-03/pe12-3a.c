#include <stdio.h>
#include "pe12-3a.h"

void set_mode(int *mode, int *n)
{
    if (*mode > 1)
    {
        printf("Invalid mode specified. Mode %s used.\n",
               (0 == *n) ? "0(metric)" : "1(US)");
    }
    else
    {
        *n = *mode;
    }
    return;
}

void get_info(int mode, double *range, double *fuel)
{
    if (0 == mode)
    {
        printf("Enter distance traveled in kilometers: ");
    }
    else
    {
        printf("Enter distance traveled in miles: ");
    }
    scanf("%lf", range);

    if (0 == mode)
    {
        printf("Enter fuel consumed in liters: ");
    }
    else
    {
        printf("Enter fuel consumed in gallons: ");
    }
    scanf("%lf", fuel);

    return;
}

void show_info(int mode, double range, double fuel)
{
    if (0 == mode)
    {
        printf("Fuel consumption is %.2lf liters per 100 km.\n",
               (fuel / range) * 100);
    }
    else
    {
        printf("Fuel consumption is %.1lf miles per gallon.\n",
               range / fuel);
    }
    return;
}