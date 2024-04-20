#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "tree.h"

int menu(void);
void addpet(Tree *pt);
void droppet(Tree *pt);
void showpets(const Tree *pt);
void findpet(const Tree *pt);
void printitem(Item item);
void uppercase(char *str);
char *s_gets(char *st, int n);
void print_all_pets(Item item);
void my_malloc(Item *item);
void print_same_pets(Item item, const char *str);
void my_traverse(const Trnode *root, void (*pfun)(Item item, const char *temp), const char *str);
void pets_count(int *count, int *temp);

int main(void)
{
    Tree pets;
    int choice;
    int count, temp;
    count = temp = 0;

    InitializeTree(&pets);
    while ((choice = menu()) != 'q')
    {
        switch (choice)
        {
            case 'a':
            {
                addpet(&pets);
                break;
            }
            case 'l':
            {
                showpets(&pets);
                break;
            }
            case 'f':
            {
                findpet(&pets);
                break;
            }
            case 'n':
            {
                count = TreeItemCount(&pets);
                pets_count(&count, &temp);
                printf("%d pets in club\n", count);
                break;
            }
            case 'd':
            {
                droppet(&pets);
                break;
            }
            default:
            {
                puts("Switching error");
            }
        }
    }
    DeleteAll(&pets);
    puts("Bye.");

    return 0;
}

int menu(void)
{
    int ch;

    puts("Nerfville Pet Club Membership Program");
    puts("Enter the letter corresponding to your choice:");
    puts("a) add a pet          l) show list of pets");
    puts("n) number of pets     f) find pets");
    puts("d) delete a pet       q) quit");
    while ((ch = getchar()) != EOF)
    {
        while (getchar() != '\n')
            continue;
        ch = tolower(ch);
        if (strchr("alrfndq", ch) == NULL)
        {
            puts("Please enter an a, l, f, n, d, or q:");
        }
        else
        {
            break;
        }
    }
    if (ch == EOF)
    {
        ch = 'q';
    }
    return ch;
}

void addpet(Tree *pt)
{
    Item temp;

    if (TreeIsFull(pt))
    {
        puts("No room in the club!");
    }
    else
    {
        puts("Please enter name of pet:");
        s_gets(temp.petname, SLEN);
        my_malloc(&temp); //分配内存至项目中的指针域;
        puts("Please enter pet kind:");
        s_gets(temp.many_petkinds->petkind, SLEN);
        uppercase(temp.petname);
        uppercase(temp.many_petkinds->petkind);
        AddItem(&temp, pt);
        free(temp.many_petkinds);
    }
    return;
}

void showpets(const Tree *pt)
{
    if (TreeIsEmpty(pt))
    {
        puts("No entries!");
    }
    else
    {
        Traverse(pt, printitem);
    }
    return;
}

void printitem(Item item)
{
    if (1 == item.pets_count) //只有一个同名宠物的情况;
    {
        printf("Pet: %-19s  Kind: %-19s\n", item.petname,
               item.many_petkinds->petkind);
    }
    else //结点中包含有多个同名不同种宠物的情况;
    {
        print_all_pets(item);
    }
    return;
}

void findpet(const Tree *pt)
{
    Item temp;

    if (TreeIsEmpty(pt))
    {
        puts("No entries!");
        return;
    }
    puts("Please enter name of pet you wish to find:");
    s_gets(temp.petname, SLEN);
    uppercase(temp.petname);
    if (InTree(&temp, pt))
    {
        printf("All kinds of the %s pets:\n", temp.petname);
        my_traverse(pt->root, print_same_pets, temp.petname);
        //若是此宠物存在于俱乐部中则打印所有相同种类的宠物;
    }
    else
    {
        printf("%s is not a member.\n", temp.petname);
    }
    return;
}

void droppet(Tree *pt)
{
    Item temp;

    if (TreeIsEmpty(pt))
    {
        puts("No entries!");
        return;
    }
    puts("Please enter name of pet you wish to delete:");
    s_gets(temp.petname, SLEN);
    my_malloc(&temp); //分配内存至项目中的指针域;
    puts("Please enter pet kind:");
    s_gets(temp.many_petkinds->petkind, SLEN);
    uppercase(temp.petname);
    uppercase(temp.many_petkinds->petkind);
    printf("%s the %s ", temp.petname, temp.many_petkinds->petkind);
    if (DeleteItem(&temp, pt))
    {
        printf("is dropped from the club.\n");
    }
    else
    {
        printf("is not a member.\n");
    }
    free(temp.many_petkinds);
    return;
}

void uppercase(char *str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
    return;
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

void print_all_pets(Item item)
{
    Kind *temp = item.many_petkinds;

    while (temp != NULL)
    {
        printf("Pet: %-19s  Kind: %-19s\n", item.petname,
               temp->petkind);
        temp = temp->next;
    }
    return;
}

void my_malloc(Item *item)
{
    if ((item->many_petkinds = (Kind *)malloc(sizeof(Kind))) == NULL)
    {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return;
}

void print_same_pets(Item item, const char *str)
{
    Kind *temp = item.many_petkinds;

    while (temp != NULL)
    {
        if (0 == strcmp(item.petname, str)) //打印名字相同的不同种类的宠物;
        {
            printf("Pet: %-19s  Kind: %-19s\n", item.petname,
                   temp->petkind);
        }
        temp = temp->next;
    }
    return;
}

void my_traverse(const Trnode *root, void (*pfun)(Item item, const char *temp), const char *str)
{
    if (root != NULL)
    {
        my_traverse(root->left, pfun, str);
        (*pfun)(root->item, str);
        my_traverse(root->right, pfun, str);
    }
    return;
}

void pets_count(int *count, int *temp)
{
    *count -= *temp;
    *temp += *count;
    return;
}
