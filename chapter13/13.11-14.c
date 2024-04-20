#include <stdio.h>
#include <stdlib.h>
#define ROWS 20
#define COLS 30
#define LEVELS 10
#define LEN 50
const char trans[LEVELS + 1] = " .':~*=&%#"; //存储需要转换的字符;

int clean_distortion(int (*a)[COLS], int rows, int x, int y);
void change(int (*a)[COLS], char (*b)[COLS], int rows);

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

    for (row = 0; row < ROWS; row++)
    {
        for (col = 0; col < COLS; col++)
        {
            figure[row][col] = clean_distortion(figure, ROWS, row, col);
        }
    }
    change(figure, picture, ROWS);
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

int clean_distortion(int (*a)[COLS], int rows, int x, int y)
{
    int i = 0, average = 0, cnt = 0, sur = 0;
    int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for (i = 0; i < 4; ++i)
    {
        int dx = x + d[i][0], dy = y + d[i][1];
        if (dx < 0 || dx >= ROWS || dy < 0 || dy >= COLS) continue;
        ++sur;
        if (abs(a[x][y] - a[dx][dy]) > 1)
        {
            ++cnt, average += a[dx][dy];
        }
    }
    return cnt != sur ? a[x][y] : 1.0 * average / cnt + 0.5;
}

void change(int (*a)[COLS], char (*b)[COLS], int rows)
{
    int row, col;

    for (row = 0; row < ROWS; row++)
    {
        for (col = 0; col < COLS; col++)
        {
            b[row][col] = trans[a[row][col]];
        }
    }
    return;
}
