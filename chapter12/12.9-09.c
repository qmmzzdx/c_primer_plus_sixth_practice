#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 256

int main(void)
{
    int i, n;
    char **pt;
    static char temp[LEN];

    printf("How many words do you wish to enter? ");
    scanf("%d", &n);
    if ((pt = (char **)malloc(n * sizeof(char *))) != NULL)
    {
        printf("Enter %d words now:\n", n);
        for (i = 0; i < n; i++)
        {
            scanf("%255s", temp);
            pt[i] = (char *)malloc((strlen(temp) + 1) * sizeof(char));
            if (NULL == pt[i])
            {
                printf("Memory allocation failed!\n");
                exit(EXIT_FAILURE);
            }
            strcpy(pt[i], temp);
        }
        printf("Here are your words:\n");
        for (i = 0; i < n; i++)
        {
            puts(pt[i]);
            free(pt[i]);
            pt[i] = NULL;
        }
        free(pt);
        pt = NULL;
    }
    else
    {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}
