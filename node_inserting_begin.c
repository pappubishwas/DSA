#include<stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node* add_beg(struct node* head,int d){
    struct node *ptr=malloc(sizeof(struct node));
    ptr->data=d;
    ptr->link=NULL;
    ptr->link=head;
    head=ptr;
    return head;
}
int main()
{
    struct node *head=malloc(sizeof(struct node));
    head->data=23;
    head->link=NULL;

    struct node *ptr=malloc(sizeof(struct node));
    ptr->data=90;
    ptr->link=NULL;

    head->link=ptr;

    int dt=80;

    head=add_beg(head,dt);
    ptr=head;
    while (ptr!=NULL)
    {
        printf("%d  ",ptr->data);
        ptr=ptr->link;
    }
    
}