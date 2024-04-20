#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define LEN 14
#define SEATS 12

typedef struct
{
    int seat_id;
    bool status;
    char last[LEN];
    char first[LEN];
} plane;

int getmenu(void);
int get_first(void);
int openings(const plane pl[], int n);
void show_empty_seats(const plane pl[], int n);
void list_assign(plane *ps[], int n);
void assign_seat(plane pl[], int n);
void delete_seat(plane pl[], int n);
void show_seats(const plane pl[]);
void sort(plane *array[], int n);
void makelist(const plane pl[], char *str, int kind);
char *s_gets(char *st, int n);
void eatline(void);

int main(void)
{
    int i, choice;
    plane plane_seat[SEATS];
    plane *ps[SEATS];

    for (i = 0; i < SEATS; i++)
    {
        ps[i] = &plane_seat[i];
    }
    for (i = 0; i < SEATS; i++)
    {
        plane_seat[i].status = false;
        plane_seat[i].seat_id = i + 1;
    }
    while ((choice = getmenu()) != 'f')
    {
        switch (choice)
        {
            case 'a':
            {
                printf("There are %d empty seats.\n", openings(plane_seat, SEATS));
                break;
            }
            case 'b':
            {
                show_empty_seats(plane_seat, SEATS);
                break;
            }
            case 'c':
            {
                list_assign(ps, SEATS);
                break;
            }
            case 'd':
            {
                assign_seat(plane_seat, SEATS);
                break;
            }
            case 'e':
            {
                delete_seat(plane_seat, SEATS);
                break;
            }
        }
        putchar('\n');
    }
    puts("Bye from Colossus Airlines!");

    return 0;
}

int getmenu(void)
{
    int ch;

    puts("To choose a function, enter its letter label:");
    puts("a) Show number of empty seats");
    puts("b) Show list of empty seats");
    puts("c) Show alphabetical list of seat");
    puts("d) Assign a customer to a seat");
    puts("e) Delete a seat assignment");
    puts("f) Quit");
    printf("Please you enter to choose: ");
    while (ch = get_first(), NULL == strchr("abcdef", ch))
    {
        printf("Invalid data! Please you choose again: ");
    }
    return ch;
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

int openings(const plane pl[], int n) //显示空座位的数量;
{
    int seat;
    int count = 0;

    for (seat = 0; seat < n; seat++)
    {
        if (pl[seat].status == false)
        {
            count++;
        }
    }
    return count;
}

void list_assign(plane *ps[], int n) //显示按照字母序列排序后的座位表;
{
    int i;

    if (openings(*ps, n) == SEATS)
    {
        puts("All seats are empty.");
    }
    else
    {
        sort(ps, n);
        for (i = 0; i < SEATS; i++)
        {
            if (ps[i]->status == true)
            {
                printf("Seat %d: %s, %s\n", ps[i]->seat_id, ps[i]->last, ps[i]->first);
            }
        }
    }
}

void show_seats(const plane pl[]) //显示已分配的座位;
{
    int i;

    puts("Seats currently taken:");
    for (i = 0; i < SEATS; i++)
    {
        if (pl[i].status == true)
        {
            printf("Seat %d: %s, %s\n", pl[i].seat_id, pl[i].last, pl[i].first);
        }
    }
}

void sort(plane *array[], int n) //按照ASCII码进行座位排序;
{
    int i, j;
    plane *temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(array[j]->last, array[i]->last) < 0)
            {
                temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }
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

void show_empty_seats(const plane pl[], int n) //显示空座位的信息;
{
    char seating[3 * SEATS];

    if (openings(pl, n) == 0)
    {
        puts("All seats are assigned");
    }
    else
    {
        makelist(pl, seating, false);
        printf("The following seats are available: ");
        puts(seating);
    }
}

void makelist(const plane pl[], char *str, int kind) //为分配和删除座位提供当前处理的座位数;
{
    int seat;
    char temp[LEN];

    *str = '\0'; //清空str中的内容;
    for (seat = 0; seat < SEATS; seat++)
    {
        if (pl[seat].status == kind)
        {
            sprintf(temp, "%d ", pl[seat].seat_id);
            strcat(str, temp);
        }
    }
}

void assign_seat(plane pl[], int n) //分配空余座位;
{
    int ch, seat, flag;
    char list[3 * SEATS];

    if (openings(pl, n) == false)
    {
        puts("All seats are assigned. Can't assign again!");
    }
    else
    {
        makelist(pl, list, false);
        printf("Available seats: %s\n", list);
        printf("Which seat do you want? Please you enter from the lists: ");
        do
        {
            while (scanf("%d", &seat) != 1)
            {
                eatline();
                printf("Seats: %s\n", list);
                printf("Enter a number from the lists: ");
            }
            if (seat < 1 || seat > SEATS || pl[seat - 1].status == true)
            {
                printf("Seats: %s\n", list);
                printf("Enter a number from the lists: ");
                flag = 1;
            }
            else
            {
                flag = 0;
            }
        } while (1 == flag); //本循环判断并处理用户的错误输入;

        eatline();
        puts("Enter first name:");
        s_gets(pl[seat - 1].first, LEN);
        puts("Enter last name:");
        s_gets(pl[seat - 1].last, LEN);
        printf("%s %s assigned to seat %d.\n", pl[seat - 1].first, pl[seat - 1].last, seat);

        printf("Enter a to accept assignment, c to cancel it: ");
        ch = get_first();
        while (strchr("ac", ch) == NULL)
        {
            printf("Please enter a or c: ");
            ch = get_first();
        }
        if (ch == 'a')
        {
            pl[seat - 1].status = true;
            puts("Passenger assigned to seat.");
        }
        else if (ch == 'c')
        {
            puts("Passenger not assigned.");
        }
    }
}

void delete_seat(plane pl[], int n) //删除已分配的座位;
{
    int ch, seat, flag;
    char list[3 * SEATS];

    if (openings(pl, n) == SEATS)
    {
        puts("All seats already are empty. Can't delete!");
    }
    else
    {
        show_seats(pl);
        makelist(pl, list, true);
        printf("Enter the number of the seat to be deleted: ");
        do
        {
            while (scanf("%d", &seat) != 1)
            {
                eatline();
                printf("Seats: %s\n", list);
                printf("Enter a number from the lists:");
            }
            if (seat < 1 || seat > SEATS || pl[seat - 1].status == false)
            {
                printf("Seats: %s\n", list);
                printf("Enter a number from this list:");
                flag = 1;
            }
            else
            {
                flag = 0;
            }
        } while (1 == flag);

        eatline();
        printf("%s %s to be canceled for seat %d.\n", pl[seat - 1].first, pl[seat - 1].last, seat);
        printf("Enter d to delete assignment, a to abort: ");
        ch = get_first();
        while (strchr("da", ch) == NULL)
        {
            printf("Please enter d or a: ");
            ch = get_first();
        }
        if (ch == 'd')
        {
            pl[seat - 1].status = false;
            puts("Passenger dropped.");
        }
        else if (ch == 'a')
        {
            puts("Passenger retained.");
        }
    }
}
