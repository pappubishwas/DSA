#include<stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};

int main()
{
    struct node *head=malloc(sizeof(struct node));
    head->data=23;
    head->link=NULL;

    struct node *ptr=malloc(sizeof(struct node));
    ptr->data=90;
    ptr->link=NULL;

    head->link=ptr;

    int d=80;
    struct node *temp;
    ptr=head;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=d;
    temp->link=NULL;

    while (ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=temp;
    //add_node(head,dt);
    ptr=head;
    while (ptr!=NULL)
    {
        printf("%d  ",ptr->data);
        ptr=ptr->link;
    }
}