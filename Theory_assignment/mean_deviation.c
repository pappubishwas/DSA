#include<stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    int n,*a,i,sum;
    printf("Enter how many element you want : ");
    scanf("%d",&n);
    a=(int *)malloc(n*sizeof(int));
    for (i = 0; i < n; i++)
        scanf("%d",(a+i));
    for ( i = 0; i < n; i++)
        sum+=a[i];

    float mean=(float)sum/n;
    float s=0;
    for ( i = 0; i < n; i++)
        s+=pow(((float)a[i]-mean),2);

    float std=sqrt(s/n);
    
    printf("Mean value: %.3lf  \nStandard deviation : %.3f \n",mean,std);
    
}