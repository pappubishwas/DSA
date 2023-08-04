#include<stdio.h>
#include <stdlib.h>
int main(){
    int n,*a,*b,*c,i;
    printf("Enter how many element you want : ");
    scanf("%d",&n);
    a=(int *)malloc(n*sizeof(int));
    b=(int *)malloc(n*sizeof(int));
    c=(int *)malloc(n*sizeof(int));
    printf("Enter the first array elements: ");
    for (i = 0; i < n; i++)
        scanf("%d",(a+i));
    printf("Enter the second array elements: ");    
    for (i = 0; i < n; i++)
        scanf("%d",(b+i));

    for ( i = 0; i < n; i++)
        c[i]=a[i]+b[i];

    printf("Addition of two array: ");    
    for (i = 0; i < n; i++)
        printf("%d ",*(c+i)); 
return 0;           
}