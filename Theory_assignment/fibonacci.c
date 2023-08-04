#include<stdio.h>
#include <stdlib.h>
int main(){
    int n,a[10],i;
    a[0]=0;a[1]=1;
    for ( i = 2; i < 10; i++)
        a[i]=a[i-2]+a[i-1];
    
    printf("Frist 10 fibonacci numbers: ");
    for(i=0;i<10;i++)
        printf("%d ",a[i]);
}