// Q2. Write a program to multiply two matrices and display it using function.
#include <stdio.h>
#include <stdlib.h>
void readData(int **array, int r, int c)
{
    int i, j;
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &array[i][j]);
}
void mult(int **array, int **array2, int **mul, int r, int m, int p)
{
    int i, j, k;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < m; j++)
        {
            mul[i][j] = 0;
            for (k = 0; k < p; k++)
                mul[i][j] += array[i][k] * array2[k][j];
        }
    }
}
int main()
{
    int i, j, r, c, p, m, **a, **b, **result;
    // printf("How many number row you want A: ");
    // scanf("%d", &r);
    // printf("How many number colum you want A: ");
    // scanf("%d", &c);
    // printf("How many number row you want B: ");
    // scanf("%d", &p);
    // printf("How many number colum you want B: ");
    // scanf("%d", &m);
    printf("Enter number of rows and colums of matrix: ");
    scanf("%d %d",&r, &c);
    printf("Enter number of rows and colums of matrix: ");
    scanf("%d %d",&p, &m);    
    a = (int **)malloc(r * sizeof(int *));
    b = (int **)malloc(p * sizeof(int *));
    result = (int **)malloc(r * sizeof(int *));
    for (i = 0; i < r; i++)
        a[i] = (int *)malloc(c * sizeof(int));
    for (i = 0; i < p; i++)
        b[i] = (int *)malloc(m * sizeof(int));
    for (i = 0; i < r; i++)
        result[i] = (int *)malloc(m * sizeof(int));

    printf("Give the elements of matrix A : \n");
    readData(a, r, c);
    printf("Give the elements of matrix B : \n");
    readData(b, p, m);
    mult(a, b, result, r, m, p);
    printf("Add of the elements of matrix A & B : \n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf(" %d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}
// Name:Pappu Bishwas
// Roll:2106287
// Section: IT-2
