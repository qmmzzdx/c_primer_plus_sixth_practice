#include <stdio.h>
#include <string.h>
#define LEN 15
#define CSIZE 4
#define SCORES 3

struct name
{
    char fname[LEN];
    char lname[LEN];
};

struct student
{
    struct name mes;
    float grade[SCORES];
    float aver;
};

void set_students(struct student ar[], int n);
void find_averages(struct student ar[], int n);
void show_messages(const struct student ar[], int n);
void show_averages(const struct student ar[], int n);

int main(void)
{
    struct student classes[CSIZE] = {
        {"Flip", "Snide"},
        {"Clare", "Voyans"},
        {"Bingo", "Higgs"},
        {"Fawn", "Hunter"},
    };

    set_students(classes, CSIZE);
    find_averages(classes, CSIZE);
    show_messages(classes, CSIZE);
    show_averages(classes, CSIZE);

    return 0;
}

void set_students(struct student ar[], int n)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        printf("Please enter three scores for %s %s:\n", ar[i].mes.fname, ar[i].mes.lname);
        for (j = 0; j < SCORES; j++)
        {
            while (scanf("%f", &ar[i].grade[j]) != 1)
            {
                while (getchar() != '\n')
                    continue;
                printf("Please enter a number: ");
            }
        }
    }
    return;
}

void find_averages(struct student ar[], int n)
{
    int i, j;
    float sum;

    for (i = 0; i < n; i++)
    {
        for (j = 0, sum = 0.0f; j < SCORES; j++)
        {
            sum += ar[i].grade[j];
        }
        ar[i].aver = sum / SCORES;
    }
    return;
}

void show_messages(const struct student ar[], int n)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        printf("%s %s's three scores: ", ar[i].mes.fname, ar[i].mes.lname);
        for (j = 0; j < SCORES; j++)
        {
            printf("%g ", ar[i].grade[j]);
        }
        printf("\nAverage: %g\n", ar[i].aver);
    }
    return;
}

void show_averages(const struct student ar[], int n)
{
    int i;
    float total;

    for (i = 0, total = 0.0f; i < n; i++)
    {
        total += ar[i].aver;
    }
    printf("Class average: %g\n", total / n);
    return;
}
