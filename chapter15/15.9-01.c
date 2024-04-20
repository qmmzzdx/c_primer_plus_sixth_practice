#include <stdio.h>
#include <string.h>

int convert(const char *str);

int main(void)
{
    const char *pbin = "01001001";
    
    printf("binary %s is decimal %d\n", pbin, convert(pbin));
    
    return 0;
}

int convert(const char *str)
{
    int sum = 0, len = strlen(str);
    for (int i = 0; i < len; ++i)
    {
        sum = sum * 2 + (str[i] - '0');
    }
    return sum;
}
