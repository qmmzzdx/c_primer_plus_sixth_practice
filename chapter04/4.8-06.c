#include <stdio.h>
#include <string.h>

int main(void)
{
    int x, y;
    char fname[20], lname[20];

    printf("Please enter your first name: ");
    scanf("%19s", fname);
    printf("Please enter your last name: ");
    scanf("%19s", lname);
    x = strlen(fname);
    y = strlen(lname);
    printf("%s %s\n", fname, lname);
    printf("%*d %*d\n", x, x, y, y);
    printf("%s %s\n", fname, lname);
    printf("%-*d %-*d\n", x, x, y, y);

    return 0;
}
