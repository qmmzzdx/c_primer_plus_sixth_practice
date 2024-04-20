#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef unsigned int uint;
typedef struct
{
    uint id : 8;
    uint sz : 7;
    uint at : 2;
    uint b  : 1;
    uint i  : 1;
    uint u  : 1;
} font;

static font ft = {1, 12, 0, 0, 0, 0};
const char *state[4] = {"off", "on"};
const char *alignment[7] = {"left", "center", "right"};

void eatline(void);
int get_first(void);
int get_choice(void);
void change_font(void);
void change_size(void);
void change_alignment(void);
void change_toggle(int ch);

int main(void)
{
    int ch;
    
    while ((ch = get_choice()) != 'q')
    {
        switch (ch)
        {
            case 'f':
            {
                change_font();
                break;
            }
            case 's':
            {
                change_size();
                break;
            }
            case 'a':
            {
                change_alignment();
                break;
            }
            case 'b':
            case 'i':
            case 'u':
            {
                change_toggle(ch);
                break;
            }
        }
        putchar('\n');
    }
    printf("Bye!\n");
    
    return 0;
}

void eatline(void)
{
    while (getchar() != '\n')
        continue;
}

int get_first(void)
{
    int ch;

    do
    {
        ch = getchar();
    } while (isspace(ch));
    eatline();

    return ch;
}

int get_choice(void)
{
    int ch;

    printf("ID    SIZE    ALIGNMENT      B       I       U\n");
    printf("%-7u%-9u%-12s", ft.id, ft.sz, alignment[ft.at]);
    printf("%-8s%-8s%-8s\n", state[ft.b], state[ft.i], state[ft.u]);
    printf("f) change font        s) change size        a) change alignment\n");
    printf("b) toggle bold        i) toggle italic      u) toggle underline\n");
    printf("q) quit\n");

    while (ch = get_first(), NULL == strchr("fsabiuq", ch))
    {
        printf("Please enter with f, s, a, b, i, u or q: ");
    }
    return ch;
}

void change_font(void)
{
    int ch;
    uint id;
    
    printf("Enter font id (0-255): ");
    while (scanf("%u", &id) != 1)
    {
        while ((ch = getchar()) != '\n')
        {
            putchar(ch);
        }
        printf(" is not a id.\n");
        printf("Please enter a number such as 0, 5 or 255: ");
    }
    ft.id = id & 0XFF;
}

void change_size(void)
{
    int ch;
    uint sz;
    
    printf("Enter font sz (0-127): ");
    while (scanf("%u", &sz) != 1)
    {
        while ((ch = getchar()) != '\n')
        {
            putchar(ch);
        }
        printf(" is not a size.\n");
        printf("Please enter a number such as 0, 5 or 127: ");
    }
    ft.sz = sz & 0x7F;
}

void change_alignment(void)
{
    int ch;
    
    printf("Select alignment:\n");
    printf("l) left    c) center    r) right\n");
    while (ch = get_first(), NULL == strchr("lcr", ch))
    {
        printf("Please enter with l, c or r: ");
    }
    ft.at = (ch == 'l' ? 0 : ch == 'c' ? 1 : 2);
}

void change_toggle(int ch)
{
    if (ch == 'b')
    {
        ft.b ^= 1;
    }
    else if (ch == 'i')
    {
        ft.i ^= 1;
    }
    else
    {
        ft.u ^= 1;
    }
}
