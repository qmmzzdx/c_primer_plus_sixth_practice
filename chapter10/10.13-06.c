#include <stdio.h>
#define N 5

void reverse(double a[], int n);
void show_array(const double a[], int n);

int main(void)
{
    double array[N] = {1.0, 4.0, 3.0, 2.0, 5.0};

    printf("Array:\n");
    show_array(array, N);
    reverse(array, N);
    printf("After reversing:\n");
    show_array(array, N);

    return 0;
}

void reverse(double a[], int n)
{
    for (int i = 0, j = n - 1; i < j; i++, j--)
    {
        double t = a[i];
        a[i] = a[j], a[j] = t;
    }
    return;
}

void show_array(const double a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%-5g", a[i]);
    }
    putchar('\n');
}
