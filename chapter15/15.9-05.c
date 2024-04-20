#include <stdio.h>
#define TEST_NUM 13
#define ROTATE_BITS 4

char *itobs(int n, char *str);
unsigned int rotate_l(unsigned int n, unsigned int b);

int main(int argc, char *argv[])
{
    unsigned int val = TEST_NUM;
    unsigned int rot = rotate_l(val, ROTATE_BITS);
    char bstr1[8 * sizeof(int) + 1];
    char bstr2[8 * sizeof(int) + 1];
    
    printf("%u rotated is %u.\n", val, rot);
    printf("%s rotated is %s.\n", itobs(val, bstr1), itobs(rot, bstr2));
    
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

unsigned int rotate_l(unsigned int n, unsigned int b)
{
    static const int size = 8 * sizeof(int);
    b %= size;
    return (n << b) | (n >> (size - b));
}
