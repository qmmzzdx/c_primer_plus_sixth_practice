#include <stdio.h>
#define TEST_NUM 13

char *itobs(int n, char *str);
int onbits(int x);

int main(int argc, char *argv[])
{
    int x = TEST_NUM;
    char bstr[8 * sizeof(int) + 1];
    
    printf("%d(%s) has %d bit on.\n", x, itobs(x, bstr), onbits(x));
    
    return 0;
}

char *itobs(int n, char *str)
{
    int sz = 8 * sizeof(int);
    for (int i = sz - 1; i >= 0; --i, n >>= 1)
    {
        str[i] = (n & 1) + '0';
    }
    str[sz] = '\0';
    return str;
}

int onbits(int x)
{
    int sum = 0;
    for (int i = 8 * sizeof(int) - 1; i >= 0; --i)
    {
        sum += (x >> i) & 1;
    }
    return sum;
}
