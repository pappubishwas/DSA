#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
int main()
{
    struct node *head;
    head=malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;
    struct node *ptr=malloc(sizeof(struct node));
    ptr->data=12;
    ptr->link=NULL;
    head->link=ptr;

    ptr=head;
    while (ptr!=NULL)
    {
        printf(" %d ",ptr->data);
        ptr=ptr->link;
    }
    
}