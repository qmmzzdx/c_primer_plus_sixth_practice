#include <stdio.h>
#include <stdlib.h>

int *make_array(int elem, int val);
void show_array(const int ar[], int n);

int main(void)
{
    int *pa;
    int size;
    int value;

    printf("Enter the number of elements: ");
    while (scanf("%d", &size) == 1 && size > 0)
    {
        printf("Enter the initialization value: ");
        scanf("%d", &value);
        pa = make_array(size, value);
        if (pa)
        {
            show_array(pa, size);
            free(pa);
        }
        printf("Enter the number of elements (<1 to quit): ");
    }
    printf("Done.\n");

    return 0;
}

int *make_array(int elem, int val)
{
    int i;
    int *pt = (int *)malloc(elem * sizeof(int));

    if (NULL == pt)
    {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    printf("Output %d numbers:\n", val);
    for (i = 0; i < elem; i++)
    {
        pt[i] = val;
    }
    return pt;
}

void show_array(const int ar[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d%c", ar[i], (i + 1) % 8 == 0 ? '\n' : ' ');
    }
    if (n % 8 != 0)
    {
        printf("\n");
    }
}
