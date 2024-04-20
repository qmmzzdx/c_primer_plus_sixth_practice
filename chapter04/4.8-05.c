#include <stdio.h>

int main(void)
{
    float speed, size;

    printf("Please enter net speed(Mb/s): ");
    scanf("%f", &speed);
    printf("Please enter file size(MB): ");
    scanf("%f", &size);
    printf("At %.2f megabits per second, ", speed);
    printf("a file of %.2f megabytes\n", size);
    printf("downloads in %.2f seconds.\n", size * 8 / speed);

    return 0;
}
