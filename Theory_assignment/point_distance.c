#include<stdio.h>
#include<stdlib.h>
struct dis
{
    int ft,inch;
};
int main()
{
    struct dis d1,d2,add;
    printf("Enter first distance in feet and inch: ");
    scanf("%d %d",&d1.ft,&d1.inch);
    printf("Enter second distance in feet and inch: ");
    scanf("%d %d",&d2.ft,&d2.inch);
    add.ft=d1.ft+d2.ft;
    add.inch=d1.inch+d2.inch;
    if (add.inch>=12)
    {
        add.ft+=(add.inch)/12;
        add.inch=add.inch%12;
    }
    printf("\nAddition of two distance in feet and inch : %d' %d\"",add.ft,add.inch);
}