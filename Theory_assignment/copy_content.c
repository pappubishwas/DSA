#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    int roll;
    char name[20], branch[20], gender[10];
};
// void readData(struct student );
// //void copy(struct student,struct student);
// void display(struct student);
int main()
{

    struct student s1, s2;
    printf("Enter your name: ");
    fflush(stdin);
    gets(s1.name);
    printf("Enter your roll: ");
    scanf("%d", &s1.roll);
    printf("Enter your Gender:");
    fflush(stdin);
    gets(s1.gender);
    printf("Enter your Branch: ");
    fflush(stdin);
    gets(s1.branch);
    s2 = s1;

    printf("\nName:%s", s2.name);
    printf("\nRoll:%d", s2.roll);
    printf("\nGender:%s", s2.gender);
    printf("\nBranch: %s", s2.branch);

    return 0;
}




// void readData(struct student p){

//             printf("Enter your name: ");
//             fflush(stdin);
//             gets(p.name);
//             printf("Enter your roll: ");
//             scanf("%d",&p.roll);
//             printf("Enter your Gender:");
//             fflush(stdin);
//             gets(p.gender);
//             printf("Enter your Branch: ");
//             fflush(stdin);
//             gets(p.branch);

// }
// void copy(struct student p,struct student q){
//         strcpy(q.name,p.name);
//         strcpy(q.gender,p.gender);
//         strcpy(q.branch,p.branch);
//         q.roll=p.roll;
// }

void display(struct student p)
{

    printf("\nName:%s", p.name);
    printf("\nRoll:%d", p.roll);
    printf("\nGender:%s", p.gender);
    printf("\nBranch: %s", p.branch);
}