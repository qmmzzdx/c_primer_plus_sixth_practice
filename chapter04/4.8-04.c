#include <stdio.h>

int main(void)
{
    float heigh;
    char name[30];

    printf("Please enter your name: ");
    scanf("%29s", name);
    printf("Hello! %s, how tall you are(inch): ", name);
    scanf("%f", &heigh);
    printf("%s, you are %.3f feet tall\n", name, heigh / 12.0);

    return 0;
}
