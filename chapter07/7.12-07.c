#include <stdio.h>
#define EXTRA_HOUR 1.5
#define BASE_TAX 0.15
#define EXTRA_TAX 0.2
#define EXCEED_TAX 0.25

int main(void)
{
    double hours = 0.0, tax, taxed_salary;

    printf("Enter the working hours a week: ");
    while (scanf("%lf", &hours) != 1 || hours < 0)
    {
        while (getchar() != '\n')
            continue;
        printf("Please enter a number(>= 0): ");
    }
    double salary = (hours > 40 ? (40 + 1.5 * (hours - 40)) : hours) * 10.0;
    if (salary <= 300)
    {
        tax = salary * BASE_TAX;
    }
    else if (salary <= 450)
    {
        tax = 300 * BASE_TAX + (salary - 300) * EXTRA_TAX;
    }
    else
    {
        tax = 300 * BASE_TAX + 150 * EXTRA_TAX + (salary - 450) * EXCEED_TAX;
    }
    taxed_salary = salary - tax;
    printf("salary(before taxed): $%g\n", salary);
    printf("tax: $%g\n", tax);
    printf("salary(after taxed): $%g\n", taxed_salary);

    return 0;
}
