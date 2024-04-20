#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 256

int main(int argc, char *argv[])
{
    FILE *f1;
    FILE *f2;
    char str1[LEN], str2[LEN];

    if (argc != 3)
    {
        printf("Usage: %s file1 file2\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((f1 = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((f2 = fopen(argv[2], "r")) == NULL)
    {
        fprintf(stderr, "Can't open file %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    char *s1 = fgets(str1, LEN, f1);
    char *s2 = fgets(str2, LEN, f2);
    while (s1 || s2)
    {
        int len1 = strlen(str1), len2 = strlen(str2);
        if (str1[len1 - 1] == '\n')
        {
            str1[len1 - 1] = '\0';
        }
        if (str2[len2 - 1] == '\n')
        {
            str2[len2 - 1] = '\0';
        }
        if (s1)
        {
            printf("%s", str1);
        }
        if (s2)
        {
            printf("%s", str2);
        }
        putchar('\n');
        s1 = fgets(str1, LEN, f1), s2 = fgets(str2, LEN, f2);
    }
    if (fclose(f1) != 0)
    {
        fprintf(stderr, "Can't close %s\n", argv[1]);
    }
    if (fclose(f2) != 0)
    {
        fprintf(stderr, "Can't close %s\n", argv[2]);
    }

    return 0;
}
