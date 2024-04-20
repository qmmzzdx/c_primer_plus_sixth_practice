#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10
#define CONTINUE 0
#define DONE 1

struct book
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

struct pack
{
    struct book books;
    bool canceled;
};

char *s_gets(char *st, int n);
int get_first(const char *str);
int get_books(struct pack *pb);
void update(struct pack *item);
void eatline(void);

int main(void)
{
    struct pack library[MAXBKS];
    int count = 0;
    int deleted = 0;
    int index, filecount, open;
    FILE *pbooks;
    int size = sizeof(struct book);

    if ((pbooks = fopen("book.dat", "rb")) != NULL)
    {
        while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
        {
            if (count == 0)
            {
                puts("Current contents of book.dat:");
            }
            printf("%s by %s: $%.2f\n", library[count].books.title,
                   library[count].books.author, library[count].books.value);
            printf("Do you want to change or delete this entry(y/n)?\n");
            printf("Please you enter to choose: ");
            if (get_first("yn") == 'y')
            {
                printf("Enter c to change, d to delete entry: ");
                if (get_first("cd") == 'd')
                {
                    library[count].canceled = true; //作为删除的标记;
                    deleted++;
                    puts("Flag marked for deletion(The space for the next book).");
                }
                else
                {
                    update(&library[count]); //修改原书籍的内容;
                }
            }
            else
            {
                library[count].canceled = false;
            }
            count++;
        }
        if (fclose(pbooks) != 0)
        {
            fprintf(stderr, "Error in closing file.\n");
        }
    }
    filecount = count - deleted; //不用删除的书籍数量;
    if (count == MAXBKS)
    {
        fputs("The book.dat file is full.", stderr);
        exit(EXIT_FAILURE);
    }

    if (deleted > 0)
    {
        printf("If you delete some books, you should enter books to replace.\n");
    }
    puts("Please add new book titles.");
    puts("Press [enter] at the start of a line to stop.");
    open = 0;
    while (filecount < MAXBKS)
    {
        if (filecount < count) //删除书的循环次数, 无法直接删除, 只能用新书替换;
        {
            while (library[open].canceled == false)
            {
                open++; //跳转到要删除的书的位置处;
            }
            if (get_books(&library[open]) == DONE)
            {
                break; //若未输入新书覆盖原有书籍则循环终止;
            }
        }
        else if (get_books(&library[filecount]) == DONE)
        {
            break; //添加新的书籍;
        }
        filecount++;
        if (filecount < MAXBKS)
        {
            puts("Enter the next book title.");
        }
    }
    filecount = (filecount < count ? count : filecount);
    puts("Here is the list of your books:");
    for (index = 0; index < filecount; index++)
    {
        if (library[index].canceled == false)
        {
            printf("%s by %s: $%.2f\n", library[index].books.title,
                   library[index].books.author, library[index].books.value);
        }
    }
    if ((pbooks = fopen("book.dat", "wb")) == NULL)
    {
        fputs("Can't open book.dat file for output.\n", stderr);
        exit(EXIT_FAILURE);
    }
    for (index = 0; index < filecount; index++)
    {
        if (library[index].canceled == false)
        {
            fwrite(&(library[index].books), size, 1, pbooks); //直接修改原文本内容;
        }
    }
    if (fclose(pbooks) != 0)
    {
        fprintf(stderr, "Error in closing file.\n");
    }
    puts("Bye.");

    return 0;
}

int get_first(const char *str) //获取输入选择的函数;
{
    int ch;

    ch = tolower(getchar());
    while (strchr(str, ch) == NULL)
    {
        printf("Invalid data! Please enter again: ");
        eatline();
        ch = tolower(getchar());
    }
    eatline();

    return ch;
}

int get_books(struct pack *pb) //保存用户输入的书籍的数据;
{
    int status = CONTINUE;

    if (s_gets(pb->books.title, MAXTITL) == NULL || pb->books.title[0] == '\0')
    {
        status = DONE; //若是输入EOF或换行符则改变status的值并将其返回;
    }
    else
    {
        printf("Now enter the author.\n");
        s_gets(pb->books.author, MAXAUTL);
        printf("Now enter the value.\n");
        while (scanf("%f", &pb->books.value) != 1)
        {
            eatline();
            puts("Please enter a valid value: ");
        }
        eatline();
        pb->canceled = false;
    }
    return status;
}

void update(struct pack *item)
{
    int ch;
    struct book copy;

    copy = item->books; //保存原书的内容以便修改;
    puts("============================================");
    puts("t) modify title a) modify author");
    puts("v) modify value s) quit and save changes");
    puts("q) quit and ignore changes");
    puts("============================================");
    printf("Please you enter to choose: ");
    while ((ch = get_first("tavsq")) != 's' && ch != 'q')
    {
        switch (ch)
        {
            case 't':
            {
                printf("Please enter new title: ");
                s_gets(copy.title, MAXTITL);
                break;
            }
            case 'a':
            {
                printf("Please enter new author: ");
                s_gets(copy.author, MAXAUTL);
                break;
            }
            case 'v':
            {
                printf("Please enter new value: ");
                while (scanf("%f", &copy.value) != 1)
                {
                    eatline();
                    puts("Please enter a valid value: ");
                }
                eatline();
                break;
            }
        }
        puts("============================================");
        puts("t) modify title a) modify author");
        puts("v) modify value s) quit, saving changes");
        puts("q) quit, ignore changes");
        puts("============================================");
        printf("You can choose again: ");
    }
    if (ch == 's')
    {
        item->books = copy; //修改原书的内容;
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

void eatline(void)
{
    while (getchar() != '\n')
        continue;
}
