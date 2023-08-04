#include<stdio.h>
#include <stdlib.h>
int main(){
    int n,*a,i,max,min;
    printf("Enter how many element you want : ");
    scanf("%d",&n);
    a=(int *)malloc(n*sizeof(int));
    for (i = 0; i < n; i++)
    scanf("%d",(a+i));
    max=a[0];min=a[0];
    for ( i = 1; i < n; i++){
        if(max<a[i]) max=a[i];
        if(min>a[i]) min=a[i];
    }
    printf("Maximum value: %d  \nMinimum value: %d \n",max,min);
    
}