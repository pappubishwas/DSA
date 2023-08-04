#include<stdio.h>
#include <stdlib.h>
int main(){
    int i=0;
    char a[50];
    printf("Enter the string : ");
    gets(a);
    while (a[i]!='\0')
        i++;
    printf("String length is : %d",i);
    
return 0;    
}