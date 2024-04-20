#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40
#define SLEN 5

struct names
{
    char first[LEN];
    char last[LEN];
};

int comp(const void *p1, const void *p2);
void show_names(const struct names *begin, int n);

int main(void)
{
    struct names staff[SLEN] = {
        {"Francy, card"},
        {"Coffee, cancy"},
        {"Stephen, lory"},
        {"Jack, rosery"},
        {"qmmzzdx, god"},
    };
    puts("Random list:");
    show_names(staff, SLEN);
    qsort(staff, SLEN, sizeof(struct names), comp);
    puts("\nSorted list:");
    show_names(staff, SLEN);

    return 0;
}

int comp(const void *p1, const void *p2)
{
    const struct names *ps1 = (const struct names *)p1;
    const struct names *ps2 = (const struct names *)p2;

    int res = strcmp(ps1->last, ps2->last);
    return res != 0 ? res : strcmp(ps1->first, ps2->first);
}

void show_names(const struct names *begin, int n)
{
    const struct names *end = begin + n;

    while (begin < end)
    {
        printf("%s %s\n", begin->first, begin->last);
        ++begin;
    }
    return;
}
