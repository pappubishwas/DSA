#include<stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
}*head=NULL;

void add_node( int d)
{
    struct node *ptr, *temp;
    
    temp=(struct node*)malloc(sizeof(struct node));

    temp->data=d;
    temp->link=NULL;

    if(head==NULL)
       head=temp;
    else{

        ptr=head;
    while (ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=temp;
}
}

void delete(int a){
    struct node *ptr,*temp,*pt;
    if(head==NULL){
        printf("There is no data.");
    }else if(head->data==a){
        head=head->link;
    }else{
        pt=head;
        temp=head->link;

        while(temp->data!=a && temp->link!=NULL){
            temp=temp->link;
            pt=pt->link;

        }
        if(temp->data==a)
            pt->link=temp->link;
        else
            printf("Data not found.\n");    
    }
}

void delete_pos(int p){
    struct node *ptr,*temp,*pt;
    int c=1;
    if(head==NULL){
        printf("There is no data.");
    }else if(p==1){
        head=head->link;
    }else{
        pt=head;
        temp=head->link;

        while(c<p-1 && temp->link!=NULL){
            temp=temp->link;
            pt=pt->link;
            c++;
        }
        if(p==c+1)
            pt->link=temp->link;
        else
           printf("Data not found.\n");    
    }
}

int main()
{
    
    add_node(1);
    add_node(10);
    add_node(20);
    add_node(30);
    add_node(40);
    delete(10);
    delete_pos(6);
    struct node *ptr=head;
    while (ptr!=NULL)
    {
        printf("%d  ",ptr->data);
        ptr=ptr->link;
    }
}