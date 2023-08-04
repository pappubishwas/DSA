#include <stdio.h>
#include <stdlib.h>
int main()
{
    int **a, i, j, p, c;
    printf("Enter the row/colum size:");
    scanf("%d", &c);
    a = (int **)malloc(c * sizeof(int *));
    for (i = 0; i < c; i++)
        a[i] = (int *)malloc(c * sizeof(int));

    printf("Enter the elements of madtrix:\n");
    for (i = 0; i < c; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &a[i][j]);

    for (i = 0; i < c; i++)
    {
        for (j = i; j < c; j++)
        {
            p = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = p;
        }
    }
    printf("Transpose Matrix:\n");
    for (i = 0; i < c; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d  ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}