#include <stdio.h>
#include <stdlib.h>
void readData(int **, int, int);
void add(int **, int **, int **, int, int);

int main()
{
    int r, c, **a, **b, **res, i, j;
    printf("Enter number of rows and colums of matrix: ");
    scanf("%d %d", &r, &c);
    // printf("How many number row you want A: ");
    // scanf("%d",&r);
    // printf("How many number colum you want A: ");
    // scanf("%d",&c);
    a = (int **)malloc(r * sizeof(int *));
    b = (int **)malloc(r * sizeof(int *));
    res = (int **)malloc(r * sizeof(int *));
    for (i = 0; i < r; i++)
    {
        a[i] = (int *)malloc(c * sizeof(int));
        b[i] = (int *)malloc(c * sizeof(int));
        res[i] = (int *)malloc(c * sizeof(int));
    }

    printf("Give the elements of matrix A : \n");
    readData(a, r, c);
    printf("Give the elements of matrix B : \n");
    readData(b, r, c);
    add(a, b, res, r, c);
    printf("Add of the elements of matrix A & B : \n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            printf(" %d ", res[i][j]);

        printf("\n");
    }
    return 0;
}

void readData(int **p, int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            scanf("%d", &p[i][j]);
}

void add(int **p, int **q, int **result, int rows, int cols)
{
    int i, j;
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            result[i][j] = p[i][j] + q[i][j];
}