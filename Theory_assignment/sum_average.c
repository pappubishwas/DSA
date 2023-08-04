#include<stdio.h>
#include <stdlib.h>
int main(){
    int n,*a,i,sum=0;
    printf("Enter how many element you want : ");
    scanf("%d",&n);
    a=(int *)malloc(n*sizeof(int));
    for (i = 0; i < n; i++)
    scanf("%d",(a+i));
    for ( i = 0; i < n; i++){
        sum+=a[i];
    }
    float average=(float)sum/n;
    printf("Maximum value: %d  \nMinimum value: %.3f \n",sum,average);
    
}