#include <stdio.h>
#include <stdlib.h>

int bstr_to_dec(const char * str);
char *itobs(int n, char *str);

int main(int argc, char *argv[])
{
    char bstr[8 * sizeof(int) + 1];
    
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s binarynum1 binarynum2\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    int v1 = bstr_to_dec(argv[1]);
    int v2 = bstr_to_dec(argv[2]);
    printf("~%s = %s\n", argv[1], itobs(~v1, bstr));
    printf("~%s = %s\n", argv[2], itobs(~v2, bstr));
    printf("%s & %s = %s\n", argv[1], argv[2], itobs(v1 & v2, bstr));
    printf("%s | %s = %s\n", argv[1], argv[2], itobs(v1 | v2, bstr));
    printf("%s ^ %s = %s\n", argv[1], argv[2], itobs(v1 ^ v2, bstr));
    
    return 0;
}

int bstr_to_dec(const char * str)
{
    int val = 0;
    while (*str)
    {
        val = val * 2 + (*str++) - '0';
    }
    return val;
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
