#include <stdio.h>
#define TEST_NUM 13

int test_bit(int x, int pos);
char *itobs(int n, char *str);

int main(int argc, char *argv[])
{
    int x = TEST_NUM;
    int sz = 8 * sizeof(int);
    char bstr[8 * sizeof(int) + 1];
    
    printf("%d(%s):\n", x, itobs(x, bstr));
    for (int i = sz - 1; i >= 0; --i)
    {
        printf("The position %d is %d\n", i + 1, test_bit(x, i));
    }
    
    return 0;
}

int test_bit(int x, int pos)
{
    return (x >> pos) & 1;
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
