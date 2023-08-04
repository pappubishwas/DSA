#include<stdio.h>
#include <stdlib.h>

int main(){
    int i,j,r,c,o=0,z=0,**a;
    // printf("How many number row you want : ");
    // scanf("%d",&r);
    // printf("How many number colum you want: ");
    // scanf("%d",&c);
    printf("Enter number of rows and colums of matrix: ");
    scanf("%d %d",&r, &c);    
    a = (int **)malloc(r * sizeof(int *));
    for ( i = 0; i < r; i++)
        a[i]=(int *)malloc(c*sizeof(int ));

    printf("Give the elements of matrix : \n");
    for ( i = 0; i < r; i++)
    {
        for ( j = 0; j < c; j++)
        {
            scanf("%d",&a[i][j]);
            if(i==j && a[i][j]==1) o++;
            if(i!=j && a[i][j]==0) z++;
        }
        
    }
    if(r==c && o==r && z==(r*c -o)) 
    printf("Given matrix is identity matrix.");
    else
    printf("Given matrix is not identity matrix.");

    return 0;   
    
}

