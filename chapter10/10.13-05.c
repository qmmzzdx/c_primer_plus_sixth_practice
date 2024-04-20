#include <stdio.h>
#define N 5

double d_value(const double a[], int n);
void show_array(const double a[], int n);

int main(void)
{
    double array[N] = {1.0, 4.0, 3.0, 2.0, 5.0};

    printf("Array:\n");
    show_array(array, N);
    printf("Maximum minus minimum is %g.\n", d_value(array, N));

    return 0;
}

double d_value(const double a[], int n)
{
    double maxv = a[0];
    double minv = a[0];

    for (int i = 1; i < n; i++)
    {
        maxv = maxv < a[i] ? a[i] : maxv;
        minv = minv > a[i] ? a[i] : minv;
    }
    return maxv - minv;
}

void show_array(const double a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%-5g", a[i]);
    }
    putchar('\n');
}
