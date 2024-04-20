#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int search(int ch, FILE *fp);

int main(int argc, char *argv[])
{
    FILE *fp;
    int i, ch, ct;
    int count = 0;

    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s character filename[s]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if (strlen(argv[1]) != 1)
    {
        fprintf(stderr, "The second argument must be a character!\n");
        exit(EXIT_FAILURE);
    }
    if (argc == 2)
    {
        fp = stdin;
        ch = argv[1][0];
        printf("Please enter a string (EOF to quit): ");
        count = search(ch, fp);
        printf("%c appeared %d times.\n", ch, count);
    }
    else if (argc > 2)
    {
        ch = argv[1][0];
        for (i = 2; i < argc; i++)
        {
            if ((fp = fopen(argv[i], "r")) == NULL)
            {
                fprintf(stderr, "Can't open file %s\n", argv[i]);
                continue;
            }
            printf("File %s:\n", argv[i]);
            while ((ct = getc(fp)) != EOF)
            {
                putchar(ct);
            }
            rewind(fp);
            count = search(ch, fp);
            printf("%c appeared %d times in file %s\n", ch, count, argv[i]);
            if (fclose(fp) != 0)
            {
                fprintf(stderr, "Can't close file %s\n", argv[i]);
            }
        }
    }

    return 0;
}

int search(int ch, FILE *fp)
{
    int find;
    int n = 0;

    while ((find = getc(fp)) != EOF)
    {
        if (ch == find)
        {
            ++n;
        }
    }
    return n;
}
