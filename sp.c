#include<stdio.h>
#include<string.h>
struct Student
{
    int rollNo;
    char name[30];
    char gender[30];

};
void read_data(struct Student list)
{
        printf("Enter your rollNo : ");
        scanf("%d",&list.rollNo);
        printf("Enter your name :");
        scanf("%s",&list.name);
        printf("Enter your gender :");
        scanf("%s",&list.gender);
         
}
void display(struct Student list)
{  
 printf("roll : %d ",list.rollNo);
 printf("Name: %s",list.name);
 printf("Gender: %s",list.gender);
}

int main()
{

    struct Student data;
    read_data(data);
    display(data);

    return 0;
}
