#include <stdio.h>
#define N 4

void add_array(const int a[], const int b[], int c[], int n);
void show_array(const int x[], int n);

int main(void)
{
    int a[N] = {2, 4, 5, 8}, b[N] = {1, 0, 4, 6}, c[N] = {0};

    printf("Array a:\n");
    show_array(a, N);
    printf("Array b:\n");
    show_array(b, N);
    printf("Array c:\n");
    show_array(c, N);
    add_array(a, b, c, N);
    printf("Array a + array b to array c is:\n");
    show_array(c, N);

    return 0;
}

void add_array(const int a[], const int b[], int c[], int n)
{
    for (int i = 0; i < n; i++)
    {
        c[i] = a[i] + b[i];
    }
}

void show_array(const int x[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%-3d", x[i]);
    }
    putchar('\n');
}
