#include <stdio.h>
#include <stdlib.h>
#define MAX 41

int main(void)
{
    FILE *fp;
    int ct = 0;
    char words[MAX];

    if ((fp = fopen("wordy", "a+")) == NULL)
    {
        fprintf(stdout, "Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(words, MAX, fp) != NULL)
    {
        ct++;
    }
    rewind(fp);
    puts("Enter words to add to the file; press the #");
    puts("key at the beginning of a line to terminate.");
    while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
    {
        fprintf(fp, "%d: %s\n", ++ct, words);
    }

    puts("File contents:");
    rewind(fp);
    while (fgets(words, MAX, fp) != NULL)
    {
        fputs(words, stdout);
    }
    puts("Done!");
    if (fclose(fp) != 0)
    {
        fprintf(stderr, "Error in closing file\n");
    }

    return 0;
}
