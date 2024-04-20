#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#define SLEN 81

char *s_gets(char *st, int n);
int menu(void);
void showwords(const Tree *pt);
void findword(const Tree *pt);
void print_all_items(Item item);
int get_first(void);
void eatline(void);

int main(void)
{
    Tree wordcount;
    FILE *fp;
    char filename[SLEN];
    char word[SLEN];
    Item entry;
    char choice;

    printf("Please enter a filename: ");
    s_gets(filename, SLEN);

    if ((fp = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    InitializeTree(&wordcount);
    while (fscanf(fp, "%80s", word) == 1 && !TreeIsFull(&wordcount))
    {
        strcpy(entry.wrd, word);
        AddItem(&entry, &wordcount);
    }
    while ((choice = menu()) != 'q')
    {
        switch (choice)
        {
            case 's':
            {
                showwords(&wordcount);
                break;
            }
            case 'f':
            {
                findword(&wordcount);
                break;
            }
        }
        printf("\n");
    }
    DeleteAll(&wordcount);
    if (fclose(fp) != 0)
    {
        fprintf(stderr, "Can't close file %s\n", filename);
    }
    puts("Done.");

    return 0;
}

char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
        {
            *find = '\0';
        }
        else
        {
            while (getchar() != '\n')
                continue;
        }
    }
    return ret_val;
}

int menu(void)
{
    int ch;

    puts("==============================================");
    puts("           Word counting program");
    puts("Enter the letter corresponding to your choice:");
    puts("     s) show word list      f) find a word");
    puts("     q) quit");
    puts("==============================================");
    printf("Please you choose: ");
    while (ch = get_first(), NULL == strchr("sfq", ch))
    {
        printf("Please enter s, f or q: ");
    }
    return ch;
}

void showwords(const Tree *pt)
{
    if (TreeIsEmpty(pt))
    {
        puts("No words in this text.");
    }
    else
    {
        Traverse(pt, print_all_items);
    }
    return;
}

void findword(const Tree *pt)
{
    char word[SLEN];
    Item entry;
    const Item *pi;

    if (TreeIsEmpty(pt))
    {
        puts("No words in this text.");
        return;
    }
    printf("Please enter a word: ");
    scanf("%80s", word);
    eatline();
    strcpy(entry.wrd, word);
    pi = WhereInTree(&entry, pt);
    if (NULL == pi)
    {
        printf("Word %s doesn't exist in this text.\n", word);
    }
    else
    {
        printf("Word %s appeared %d times in this text.\n", word, pi->count);
    }
    return;
}

void print_all_items(Item item)
{
    printf("Word %s appeared %d times totally in this text.\n", item.wrd, item.count);
}

int get_first(void)
{
    int ch;

    do
    {
        ch = tolower(getchar());
    } while (isspace(ch));
    eatline();
    return ch;
}

void eatline(void)
{
    while (getchar() != '\n')
        continue;
}
