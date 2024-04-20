#include <stdio.h>
#define ROWS 3
#define COLS 5

void store(int n, double ar[n]);
double average2d(int rows, int cols, double ar[rows][cols]);
double max2d(int rows, int cols, double ar[rows][cols]);
void showarr2(int rows, int cols, double ar[rows][cols]);
double average(int n, const double ar[n]);

int main(void)
{
    double stuff[ROWS][COLS];

    for (int row = 0; row < ROWS; row++)
    {
        printf("Please enter %d numbers for %d row\n", COLS, row + 1);
        store(COLS, stuff[row]);
    }
    printf("Array:\n");
    showarr2(ROWS, COLS, stuff);

    for (int row = 0; row < ROWS; row++)
    {
        printf("Average for row %d is %g.\n", row + 1, average(COLS, stuff[row]));
    }
    printf("Average is %g.\n", average2d(ROWS, COLS, stuff));
    printf("Maximum is %g.\n", max2d(ROWS, COLS, stuff));
    printf("Done.\n");

    return 0;
}

void store(int n, double ar[n])
{
    for (int i = 0; i < n; i++)
    {
        printf("Please enter a number for position %d: ", i + 1);
        scanf("%lf", &ar[i]);
    }
}

double average2d(int rows, int cols, double ar[rows][cols])
{
    double sum = 0.0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum += ar[i][j];
        }
    }
    return rows * cols > 0 ? sum / (rows * cols) : 0.0; 
}

double max2d(int rows, int cols, double ar[rows][cols])
{
    double maxv = ar[0][0];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            maxv = maxv < ar[i][j] ? ar[i][j] : maxv;
        }
    }
    return maxv;
}

void showarr2(int rows, int cols, double ar[rows][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%-5g", ar[i][j]);
        }
        putchar('\n');
    }
}

double average(int n, const double ar[n])
{
    double sum = 0.0;

    for (int i = 0; i < n; i++)
    {
        sum += ar[i];
    }
    return n > 0 ? sum / n : 0.0;
}
