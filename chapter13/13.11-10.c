#include <stdio.h>
#include <stdlib.h>
#define LEN 50

int main(int argc, char *argv[])
{
    int ch;
    FILE *fp;
    long int number;
    char filename[LEN];

    printf("Please enter a filename: ");
    scanf("%49s", filename);

    if ((fp = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    printf("Please enter a file position (<0 or q to quit): ");
    while (scanf("%ld", &number) == 1 && number >= 0)
    {
        fseek(fp, number, SEEK_SET);
        while ((ch = getc(fp)) != '\n' && ch != EOF)
        {
            putchar(ch);
        }
        if (ch == EOF)
        {
            printf("The position reaches EOF.\n");
            break;
        }
        printf("\nYou can enter again (<0 or q to quit): ");
    }
    printf("Done.\n");
    if (fclose(fp) != 0)
    {
        fprintf(stderr, "Can't close file %s\n", filename);
    }

    return 0;
}
