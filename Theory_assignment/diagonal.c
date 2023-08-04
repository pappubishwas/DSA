#include<stdio.h>
#include <stdlib.h>

int main(){
    int i,j,r,c,sum=0,a[20][20];
    printf("Enter number of rows and colums of matrix: ");
    scanf("%d %d",&r, &c);
    // a = (int **)malloc(r * sizeof(int *));
    // for ( i = 0; i < r; i++)
    //     a[i]=(int *)malloc(c*sizeof(int ));

    printf("Give the elements of matrix : \n");
    for ( i = 0; i < r; i++)
        for ( j = 0; j < c; j++)
            scanf("%d",&a[i][j]);
    printf("Diagonal the elements of matrix : \n");
    for ( i = 0; i < r; i++){
        printf(" %d ",a[i][i]);
        sum+=a[i][i];
    }
    printf("\nSum of diagonal elements is %d",sum);
    return 0;   
    
}

