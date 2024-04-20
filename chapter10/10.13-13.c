#include <stdio.h>
#define ROWS 3
#define COLS 5

void store(double ar[], int n);
double average2d(double ar[][COLS], int rows);
double max2d(double ar[][COLS], int rows);
void showarr2(double ar[][COLS], int rows);
double average(const double ar[], int n);

int main(void)
{
    double stuff[ROWS][COLS];

    for (int row = 0; row < ROWS; row++)
    {
        printf("Please enter %d numbers for %d row\n", COLS, row + 1);
        store(stuff[row], COLS);
    }
    printf("Array:\n");
    showarr2(stuff, ROWS);

    for (int row = 0; row < ROWS; row++)
    {
        printf("Average for row %d is %g.\n", row + 1, average(stuff[row], COLS));
    }
    printf("Average is %g.\n", average2d(stuff, ROWS));
    printf("Maximum is %g.\n", max2d(stuff, ROWS));
    printf("Done.\n");

    return 0;
}

void store(double ar[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Please enter a number for position %d: ", i + 1);
        scanf("%lf", &ar[i]);
    }
}

double average2d(double ar[][COLS], int rows)
{
    double sum = 0.0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            sum += ar[i][j];
        }
    }
    return rows * COLS > 0 ? sum / (rows * COLS) : 0.0;
}

double max2d(double ar[][COLS], int rows)
{
    double maxv = ar[0][0];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            maxv = maxv < ar[i][j] ? ar[i][j] : maxv;
        }
    }
    return maxv;
}

void showarr2(double ar[][COLS], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%-5g", ar[i][j]);
        }
        putchar('\n');
    }
}

double average(const double ar[], int n)
{
    double sum = 0.0;

    for (int i = 0; i < n; i++)
    {
        sum += ar[i];
    }
    return n > 0 ? sum / n : 0.0;
}
