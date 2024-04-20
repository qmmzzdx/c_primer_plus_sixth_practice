#include <stdio.h>
#define N 3
#define M 5

void show_array(int n, int m, double x[n][m]);
void copy_array(int n, int m, double a[n][m], double b[n][m]);

int main(void)
{
    double a[N][M] = {
        {1.0,2.0,3.0,4.0,5.0},
        {6.0,7.0,8.0,9.0,10.0},
        {11.0,12.0,13.0,14.0,15.0},
    };
    double b[N][M] = {0.0};

    printf("Array a:\n");
    show_array(N, M, a);
    printf("Array b:\n");
    show_array(N, M, b);
    copy_array(N, M, a, b);
    printf("Copy array a to array b:\n");
    show_array(N, M, b);

    return 0;
}

void show_array(int n, int m, double x[n][m])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%-5g", x[i][j]);
        }
        putchar('\n');
    }
}

void copy_array(int n, int m, double a[n][m], double b[n][m])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            b[i][j] = a[i][j];
        }
    }
}
