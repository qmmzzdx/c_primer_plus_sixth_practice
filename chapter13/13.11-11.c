#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SLEN 256

int main(int argc, char *argv[])
{
    FILE *fp;
    char line[SLEN];

    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s string filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((fp = fopen(argv[2], "r")) == NULL)
    {
        fprintf(stderr, "Can't open file %s", argv[2]);
        exit(EXIT_FAILURE);
    }
    while (fgets(line, SLEN, fp) != NULL)
    {
        if (strstr(line, argv[1]) != NULL)
        {
            fputs(line, stdout);
        }
    }
    if (fclose(fp) != 0)
    {
        fprintf(stderr, "Can't close file %s", argv[2]);
    }

    return 0;
}
