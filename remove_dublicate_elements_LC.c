#include<stdio.h>
int main()
{
int i,j,n,a[30],b[30],p=0,t;
printf("Enter the array size: ");
scanf("%d",&n);
printf("Enter the array elements :");
for(i = 0; i < n; i++)
    scanf("%d",&a[i]);

for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
        if (a[i]>a[j]){
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
}  

for(i=0;i<n;i++)
    if (a[i]!=a[i+1])
        b[p++]=a[i];

for(i=0;i<p;i++)
    a[i]=b[i];

printf("After removing duble elements: ");
for (i=0; i<p; i++)
    printf("%d ",a[i]);

return 0;
}