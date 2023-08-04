#include<stdio.h>
#include<stdlib.h>

struct student
{
int roll;
char name[20],branch[20],gender[10];
};
void readData(struct student *,int);
void display(struct student *,int);
int main()
{
    int n;
    printf("ENter how many student information you want:");
    scanf("%d",&n);
    struct student *s;
    s=(struct student*)malloc(n * sizeof(struct student));
    readData(s,n);
    display(s,n);

    return 0;
}

void readData(struct student *p,int k){
        for(int i=0;i<k;i++){
            printf("Enter your name: ");
            fflush(stdin);
            gets((p+i)->name);
            printf("Enter your roll: ");
            scanf("%d",&(p+i)->roll);
            printf("Enter your Gender:");
            fflush(stdin);
            gets((p+i)->gender);
            printf("Enter your Branch: ");
            fflush(stdin);
            gets((p+i)->branch);
        }
}

void display(struct student *p,int k){
    for (int i = 0; i <k; i++)
    {
        printf("\n\nStudent details %d:",i+1);
        printf("\nName:%s",(p+i)->name);
        printf("\nRoll:%d",(p+i)->roll);
        printf("\nGender:%s",(p+i)->gender);
        printf("\nBranch: %s",(p+i)->branch);
    }
    
}