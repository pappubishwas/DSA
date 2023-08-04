#include<stdio.h>
int main()
{
    int i=0,a[20],temp,n,k=0;
    printf("\nHow many elements you want : ");
    scanf("%d",&n);
    printf("\nGive the elements : ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("\nBefore sliding the elements : ");
    for(i=0;i<n;i++){
        printf(" %d ",a[i]);
    }
    for ( i = 0; i < n/2; i++)
    {
        temp=a[k];
        a[k]=a[k+1];
        a[k+1]=temp;
        k=k+2;
    }
    printf("\nAfter sliding the elements : ");
    for(i=0;i<n;i++)
    printf(" %d ",a[i]);
    
}