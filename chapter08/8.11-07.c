#include <stdio.h>
#include <ctype.h>
#define EXTRA_HOUR 1.5
#define BASE_TAX 0.15
#define EXTRA_TAX 0.2
#define EXCEED_TAX 0.25

int show_menu(void);
void show_salary(double base_salary, double hours);
int get_choice(void);

int main(void)
{
    int ch;
    double n;

    while ((ch = show_menu()) != 'q')
    {
        printf("Enter the working hours a week: ");
        while (scanf("%lf", &n) != 1 || n < 0)
        {
            while (getchar() != '\n')
                continue;
            printf("Enter a positive number: ");
        }
        switch (ch)
        {
            case 'a':
            {
                show_salary(8.75, n);
                break;
            }
            case 'b':
            {
                show_salary(9.33, n);
                break;
            }
            case 'c':
            {
                show_salary(10.00, n);
                break;
            }
            case 'd':
            {
                show_salary(11.20, n);
                break;
            }
        }
        putchar('\n');
    }
    printf("Done!\n");

    return 0;
}

int get_choice(void)
{
    int ch;

    do
    {
        ch = getchar();
    } while (isspace(ch));
    while (getchar() != '\n')
        continue;

    return ch;
}

int show_menu(void)
{
    int ch;

    printf("*****************************************************************\n");
    printf("Enter the number corresponding to the desired pay rate or action:\n");
    printf("a) $8.75/hr                        b) $9.33/hr\n");
    printf("c) $10.00/hr                       d) $11.20/hr\n");
    printf("q) quit\n");
    printf("*****************************************************************\n");
    printf("Please you choose: ");
    
    ch = get_choice();
    while (ch != 'a' && ch != 'b' && ch != 'c' && ch != 'd' && ch != 'q')
    {
        printf("Please enter a, b, c, d or q: ");
        ch = get_choice();
    }
    return ch;
}

void show_salary(double base_salary, double hours)
{
    double tax, taxed_salary;
    double salary = (hours > 40 ? (40 + 1.5 * (hours - 40)) : hours) * base_salary;
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
}
