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
}}

void insert(int a){
    
    struct node *ptr,*temp;
    temp=head;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=12;
    ptr->link=NULL;
    if(head==NULL)
        head=ptr;
    else{
        head=ptr;
        ptr->link=temp;
    }
    
}

void insert_pos(int v,int p){
       struct node *ptr,*temp,*t;
       int c=1;
       ptr=(struct node*)malloc(sizeof(struct node));
       ptr->data=v;
       ptr->link=NULL;
       if(head==NULL){
        if(p>1) printf("there is no more data as for required position.");
       }else if(p==1){
        temp=head;
        head=ptr;
        ptr->link=temp;
       }
       else{

        temp=head;
        while(c<p-1 && temp->link!=NULL){
            temp=temp->link;
            c++;
        }
        t=temp->link;
        temp->link=ptr;
        ptr->link=t;
       }

}





int main()
{

    // struct node *head=malloc(sizeof(struct node));
    // head->data=23;
    // head->link=NULL;

    // struct node *ptr=malloc(sizeof(struct node));
    // ptr->data=90;
    // ptr->link=NULL;

    // head->link=ptr;

    int dt;
    
    add_node(1);
    add_node(10);
    add_node(20);
    add_node(30);
    add_node(40);
    // for (int i=0;i<10;i++){
    //     scanf("%d",&dt);
    //     add_node(dt);
    // }
    //.insert(23);
    //insert_pos(25,1);
    insert_pos(21,4);
    struct node *ptr=head;
    while (ptr!=NULL)
    {
        printf("%d  ",ptr->data);
        ptr=ptr->link;
    }
}