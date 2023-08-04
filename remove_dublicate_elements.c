#include<stdio.h>
int main()
{
int i,j,k,n,a[30],p=0,t;
printf("Enter the array size: ");
scanf("%d",&n);
printf("Enter the array elements :");
for(i = 0; i < n; i++)
    scanf("%d",&a[i]);

for(i=0;i<n;i++){
    for(j=i+1;j<n-p;j++){
        if (a[i]>a[j]){
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }else if (a[i]==a[j])
        {
            for(k=j;k<(n-p-1);k++){
                a[k]=a[k+1];
            }
            j--;
            p++;
        }
        
    }
}  

printf("After removing duble elements: ");
for (i=0; i<n-p; i++)
    printf("%d ",a[i]);

return 0;
}