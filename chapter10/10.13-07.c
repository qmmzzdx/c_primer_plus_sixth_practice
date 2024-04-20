#include <stdio.h>
#define N 2
#define M 3

void copy_arr(const double a[], double b[], int n);
void show_array(double (*x)[M], int n);

int main(void)
{
    double a[N][M] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
    };
    double b[N][M] = {0.0};

    printf("Array a:\n");
    show_array(a, N);
    printf("Array b:\n");
    show_array(b, N);
    for (int i = 0; i < N; i++)
    {
        copy_arr(a[i], b[i], M);
    }
    printf("Copying array a to array b is:\n");
    show_array(b, N);

    return 0;
}

void copy_arr(const double a[], double b[], int n)
{
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i];
    }
}

void show_array(double (*x)[M], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%-5g", x[i][j]);
        }
        putchar('\n');
    }
}
