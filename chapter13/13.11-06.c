#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40

int main(int argc, char *argv[])
{
    FILE *in, *out;
    int ch;
    char name[LEN];
    int count = 0;
    char temp[LEN];

    printf("Please enter a filename: ");
    scanf("%34s", temp);

    if ((in = fopen(temp, "r")) == NULL)
    {
        fprintf(stderr, "I could't open the file \"%s\"\n", temp);
        exit(EXIT_FAILURE);
    }
    strcpy(name, temp);
    name[LEN - 5] = '\0';
    strcat(name, ".red");
    if ((out = fopen(name, "w")) == NULL)
    {
        fprintf(stderr, "Can't create output file.\n");
        exit(3);
    }
    while ((ch = getc(in)) != EOF)
    {
        if (count++ % 3 == 0)
        {
            putc(ch, out);
        }
    }
    if (fclose(in) != 0 || fclose(out) != 0)
    {
        fprintf(stderr, "Error in closing files\n");
    }

    return 0;
}
