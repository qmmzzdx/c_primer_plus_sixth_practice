#include <stdio.h>
#include <stdlib.h>
#define ROWS 20
#define COLS 30
#define LEVELS 10
#define LEN 50
const char trans[LEVELS + 1] = " .':~*=&%#"; //存储需要转换的字符;

void change(int rows, int cols, int a[rows][cols], char b[rows][cols]);

int main(void)
{
    int row, col;
    FILE *fp1, *fp2;
    int figure[ROWS][COLS];
    char picture[ROWS][COLS];

    if ((fp1 = fopen("13.11-12.txt", "r")) == NULL)
    {
        fprintf(stderr, "Can't open file 13.11-12.txt\n");
        exit(EXIT_FAILURE);
    }
    if ((fp2 = fopen("pictures.txt", "w")) == NULL)
    {
        fprintf(stderr, "Can't open file pictures.txt\n");
        exit(EXIT_FAILURE);
    }
    for (row = 0; row < ROWS; row++)
    {
        for (col = 0; col < COLS; col++)
        {
            fscanf(fp1, "%d", &figure[row][col]);
        }
    }

    change(ROWS, COLS, figure, picture);
    printf("File 13.11-12.txt have been transformed pictures:\n");
    for (row = 0; row < ROWS; row++)
    {
        for (col = 0; col < COLS; col++)
        {
            putchar(picture[row][col]);
        }
        putchar('\n');
    }
    for (row = 0; row < ROWS; row++)
    {
        for (col = 0; col < COLS; col++)
        {
            fprintf(fp2, "%c", picture[row][col]);
        }
        putc('\n', fp2);
    }
    if (fclose(fp1) != 0)
    {
        fprintf(stderr, "Can't close file 13.11-12.txt\n");
    }
    if (fclose(fp2) != 0)
    {
        fprintf(stderr, "Can't close file pictures.txt\n");
    }

    return 0;
}

void change(int rows, int cols, int a[rows][cols], char b[rows][cols])
{
    int row, col;

    for (row = 0; row < rows; row++)
    {
        for (col = 0; col < cols; col++)
        {
            b[row][col] = trans[a[row][col]];
        }
    }
    return;
}
