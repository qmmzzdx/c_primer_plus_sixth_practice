#include <stdio.h>
#include "pe12-3a.h"

int main(void)
{
    int temp, mode;
    double range, fuel;

    printf("Enter 0 for metric mode, 1 for US mode: ");
    scanf("%d", &mode);
    temp = mode;
    while (mode >= 0)
    {
        set_mode(&mode, &temp);
        get_info(temp, &range, &fuel);
        show_info(temp, range, fuel);
        printf("Enter 0 for metric mode, 1 for US mode");
        printf("(-1 to quit): ");
        scanf("%d", &mode);
    }
    printf("Done.\n");

    return 0;
}