#include <stdio.h>
#define N 3
#define M 5

void show(int (*a)[M], int n);
void two_times(int (*a)[M], int n);

int main(void)
{
    int a[N][M] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
    };

    printf("Array:\n");
    show(a, N);
    two_times(a, N);
    printf("Double array is:\n");
    show(a, N);

    return 0;
}

void show(int (*a)[M], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%-5d", a[i][j]);
        }
        putchar('\n');
    }
}

void two_times(int (*a)[M], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < M; j++)
        {
            a[i][j] *= 2;
        }
    }
}
