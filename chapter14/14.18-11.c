#include <stdio.h>
#include <math.h>
#define LEN 5

double square(double x);
double triple(double x);
void transform(double x[], double y[], int n, double (*p)(double));
void show_array(double temp[], int n);

int main(void)
{
    double x[LEN] = {2.0, 4.0, 6.0, 8.0, 9.0}, y[LEN] = {0.0};

    printf("array:\n");
    show_array(x, LEN);

    printf("target array:\n");
    show_array(y, LEN);

    transform(x, y, LEN, sqrt);
    printf("After square root:\n");
    show_array(y, LEN);

    transform(x, y, LEN, cbrt);
    printf("After opening cube:\n");
    show_array(y, LEN);

    transform(x, y, LEN, square);
    printf("After square:\n");
    show_array(y, LEN);

    transform(x, y, LEN, triple);
    printf("After cube:\n");
    show_array(y, LEN);

    return 0;
}

double square(double x)
{
    return x * x;
}

double triple(double x)
{
    return x * x * x;
}

void transform(double x[], double y[], int n, double (*p)(double))
{
    for (int i = 0; i < n; i++)
    {
        y[i] = p(x[i]);
    }
}

void show_array(double temp[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%g ", temp[i]);
    }
    putchar('\n');
}
