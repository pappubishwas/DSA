#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coeff,exp;
    struct node *link;
};
void create(struct node **,int,int);
void polynomial(struct node **,struct node **,struct node **);
void display(struct node **);
void multply(struct node **start1,struct node **start2,struct node **start3){
        struct node *p1=*start1,*p2=*start2;
        while (p1!=NULL)
        {
            while (p2!=NULL)
            {
                create(start3,((p1->coeff)*(p2->coeff)),((p1->exp)+(p2->exp)));
                p2=p2->link;
            }
            p1=p1->link;
            
        }
        
}

void remove_dup(struct node **start3){
    struct node *p1=*start3,*p2,*dup;
    while (p1!=NULL && p1->link!=NULL)
    {
        p2=p1;
        while (p2->link!=NULL)
        {
            if (p1->exp==p2->link->exp)
            {
                p1->coeff=p1->coeff+p2->link->coeff;
                dup=p2->link;
                p2->link=p2->link->link;
                free(dup);
            }else
            p2=p2->link;
            
        }
        p1=p1->link;
    }
    
}
int main()
{
    struct node *start1=NULL,*start2=NULL,*start3=NULL;
        int k,e, t=1;
        printf("Give the first polynomial: \n");
        while(t==1)
        {
        printf("Give the coefficient : ");
        scanf("%d",&k);
        printf("Enter the exponent : ");
        scanf("%d",&e);
        create(&start1,k,e);
        printf("If want another node pres 1 || for exit any key : ");
        scanf("%d",&t);  
        }
        t=1;
        printf("\nGive the second polynomial: \n");
        while(t==1)
        {
        printf("Give the coefficient : ");
        scanf("%d",&k);
        printf("Enter the exponent : ");
        scanf("%d",&e);
        create(&start2,k,e);
        printf("If want another node pres 1 || for exit any key : ");
        scanf("%d",&t);  
        }
    
    printf("The details of first polynomial.\n");
    display(&start1);
    printf("The details of second polynomial.\n");
    display(&start2);
    // printf("The details of add two polynomial.\n");
    // polynomial(&start1,&start2,&start3);
    // display(&start3);
    multply(&start1,&start2,&start3);
    //remove_dup(&start3);
    display(&start3);
}

void create(struct node **start,int k,int e)
{
        struct node *p=(struct node*)malloc(sizeof(struct node));
        p->coeff=k;
        p->exp=e;
        p->link=NULL;
        struct node *t=*start;
        if(*start==NULL)
            *start=p;
        else{
        while (t->link!=NULL)
            t=t->link;

        t->link=p; 
        }

    
}

void display(struct node **start){
    struct node *t=*start;
   // printf("\nThe coefficientand exponent of polynomial:  \n");
        printf("Coefficient----exponent\n");
    while (t!=NULL)
    {
        printf("%d             %d\n",t->coeff,t->exp);
        //printf(" %d ",t->exp);
        t=t->link;
    }
}

void polynomial(struct node **start1,struct node **start2,struct node **start3){
    struct node *t1,*t2,*t3=*start3;
    t1=*start1;t2=*start2;

    while (t1!=NULL && t2!=NULL)
    {
        if (t1->exp>t2->exp)
        {
            create(start3,t1->coeff,t1->exp);
            t1=t1->link;
        }else if(t1->exp<t2->exp){
            create(start3,t2->coeff,t2->exp);
            t2=t2->link;
        }else{
            if(t1->coeff==(-(t2->coeff))){
                t1=t1->link;
                t2=t2->link;
            }else{
                create(start3,(t1->coeff+t2->coeff),t1->exp);
                t1=t1->link;
                t2=t2->link;
            }
        }
        
    }
    while (t1!=NULL)
    {
            create(start3,t1->coeff,t1->exp);
            t1=t1->link;
    }
    while (t2!=NULL)
    {
            create(start3,t2->coeff,t2->exp);
            t2=t2->link;
    }
    
    
}