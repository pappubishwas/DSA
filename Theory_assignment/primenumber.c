#include<stdio.h>

int main(){
    int n1,n2,i,j,flag;
    printf("Enter the interval for prime number list:");
    scanf("%d %d",&n1,&n2);
    printf("The list of prime number: ");
    for ( i = n1; i <=n2; i++)
    {
        flag=0;
        for ( j = 2; j< i; j++)
        {
            if(i%j==0) {
                flag=1;
                break;
            }
        }
        if(flag==0) printf(" %d ",i);
    }
    
}