#include<stdio.h>
void display(int array[][20],int r,int c)
{
    int i,j;
    for ( i = 0; i < r; i++)
    {
    for ( j = 0; j < c; j++)
        printf(" %d ",array[i][j]); 

    printf("\n");           
    }
    printf("\n");
}
void readData(int array[][20], int r ,int c)
{
    int i,j;
    for ( i = 0; i < r; i++)
    {
    for ( j = 0; j < c; j++)
        scanf("%d",&array[i][j]);   
    }
}


int main()
{
    int r,c,array[20][20],array2[20][20],sum[20][20],sp1[20][20],sp2[20][20],k=0,i,j;
    printf("How many number row you want : ");
    scanf("%d",&r);
    printf("How many number colum you want : ");
    scanf("%d",&c);
    printf("Give the element of matrix A: ");
    readData(array,r,c);
    printf("Matrix A :\n");
    display(array,r,c);
    printf("Give the element of matrix B: ");
    readData(array2,r,c);
    printf("Matrix B :\n");
    display(array2,r,c);
    sp1[0][0]=r;
    sp1[0][1]=c;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++){
            if(array[i][j]!=0)
            {
                k++;
                sp1[k][0]=i;
                sp1[k][1]=j;
                sp1[k][2]=array[i][j];
                sp1[0][2]=k;
            }
        }
    }
    printf("\nSparse Matrix1 : \n");
    display(sp1,k+1,3);
    k=0;
    sp2[0][0]=r;
    sp2[0][1]=c;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++){
            if(array2[i][j]!=0)
            {
                k++;
                sp2[k][0]=i;
                sp2[k][1]=j;
                sp2[k][2]=array2[i][j];
                sp2[0][2]=k;
            }
        }
    }
    printf("\nSparse Matrix2 : \n");
    display(sp2,k+1,3);

    


return 0;
}
//Name:Pappu Bishwas
//Roll:2106287
//Section: IT-2
