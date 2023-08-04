#include <stdio.h>
#include <stdlib.h>
void main()
{
int n, *list;
printf("\nEnter the no of elements:");
scanf("%d", &n);
if (n < 1)
{
printf("Incorrect Value");
return;
}
list=malloc(n*sizeof(int));
if (!list)
{
printf("Insufficient Memory");
return;
}
/* Allow the users to enter values*/ 
/* print the values */
free(list);
return; 
}