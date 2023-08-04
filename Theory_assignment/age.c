#include<stdio.h>
#include<stdlib.h>
struct age
{
    int year,month,day;
};
int leapyear(int);
int main()
{
    struct age birth,present,age;
    printf("Enter the birthdate(year month day): ");
    scanf("%d %d %d",&birth.year,&birth.month,&birth.day);
    printf("Enter the presentdate(year month day): ");
    scanf("%d %d %d",&present.year,&present.month,&present.day);
    int q=0;
    if(present.day<birth.day){
        if(present.month-1==2){
            int p=leapyear(present.year);
            if(p==1) present.day+=29;
            else present.day+=28;
        }else if(present.month==0){
            present.month=12;
            present.year-=1;
            present.day+=31;
        }else if((present.month-1)%2==0) present.day+=31;
        else present.day+=30;

        q=1;
    }
    age.day=present.day-birth.day;
    if(q==1) present.month-=1;
    if(present.month<birth.month){
        present.year-=1;
        present.month+=12;
    }
    age.month=present.month-birth.month;
    age.year=present.year-birth.year;
    printf("Age of that person :- year: %d month: %d day: %d",age.year,age.month,age.day);

}

int leapyear(int year){
    if((year%4==0) && ((year%400==0) || (year%100!=0)))  
        return 1;
    else 
        return 0;

}
