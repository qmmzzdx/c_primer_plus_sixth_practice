#include <stdio.h>

int main(void)
{
    char fname[20], lname[20];

    printf("Please enter your first name: ");
    scanf("%19s", fname);
    printf("Please enter your last name: ");
    scanf("%19s", lname);
    printf("Hello! %s, %s.\n", fname, lname);

    return 0;
}
