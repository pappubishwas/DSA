#include<stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
}*start=NULL;

void create();
void display();
int check();
void search();
void insert();
void delete();
void delete_key();
void delete_after();
void delete_before();
void sorting();
void reverse();
void reverse_node();
void print_last_n_node();
void delete_duplicate();
void insert_before();
void insert_after();

int main()
{
int c,n=1;
printf("1.Create a list .\n2.Display the list.\n3.Insert a node after a given data item.\n4.Insert a node before a given data item.\n5.Delete a node after a given data item.\n6.Delete a node before a given data item.\n7.Insert a node at any position.\n8.Delete a node at any position.\n9.Delete a node for the given key.\n10.Search for an element in the link list.\n11.Sorts the elements of  the link list.\n12.Print the elements of the reverse order.\n13.Reverse the nodes of the linked list.\n14.Print nth node from last of a link list.\n15.Delete the dublicate elements of the linked list.\n16.Exit\n");
printf("Enter the number which opertation you want: \n");
scanf("%d",&c);
while (n==1)
{
    switch (c)
    {
    case 1:
        create();
        break;
    case 2:
        display();
        break;
    case 3:
        insert_after();
        break;
    case 4:
        insert_before();
        break;
    case 5:
        delete_after();
        break;
    case 6:
        delete_before();
        break;
    case 7:
        insert();
        break;
    case 8:
        delete();
        break;
    case 9:
        delete_key();
        break;
    case 10:
        search();
        break;
    case 11:
        sorting();
        break;
    case 12:
        reverse();
        break;
    case 13:
        reverse_node();
        break;
    case 14:
        print_last_n_node();
        break;
    case 15:
        delete_duplicate();
        break;
    case 16:
    exit(0);
    }
    printf("\nPress 1 to continune || 0 to exit: ");
    scanf("%d",&n);
    if(n==0) exit(0);

    printf("1.Create a list .\n2.Display the list.\n3.Insert a node after a given data item.\n4.Insert a node before a given data item.\n5.Delete a node after a given data item.\n6.Delete a node before a given data item.\n7.Insert a node at any position.\n8.Delete a node at any position.\n9.Delete a node for the given key.\n10.Search for an element in the link list.\n11.Sorts the elements of  the link list.\n12.Print the elements of the reverse order.\n13.Reverse the nodes of the linked list.\n14.Print nth node from last of a link list.\n15.Delete the dublicate elements of the linked list.\n16.Exit\n");
    scanf("%d",&c);
}

}

void create()
{
    int k,n=1;
    while (n==1)
    {
        struct node *p=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data of node: ");
        scanf("%d",&k);
        p->data=k;
        p->link=NULL;
        struct node *t=start;
        if(start==NULL)
            start=p;
        else{
        while (t->link!=NULL)
            t=t->link;

        t->link=p; 
        }    
        printf("Press 1 to continune || press any key  to exit create function: ");
        scanf("%d",&n);
        
    }
    
}

void display(){
    struct node *t=start;
    printf("\nThe list of data:  ");
    while (t!=NULL)
    {
        printf(" %d ",t->data);
        t=t->link;
    }
}
int check(){
    if(start!=NULL)  
       return 1; // printf("This link list is not empty\n");
    else
        return 0;//printf("This link list is empty\n");
}

void search()
{
    int c=0,k;
    printf("Give data that you are searching: ");
    scanf("%d",&k);
    struct node *key=start;//=(struct node*)malloc(sizeof(struct node));
    //key=start;
    while (key!=NULL){
        c++;
        if (key->data==k){
            printf("%d is present the node at %d position.",k,c);
            break;
        }
        key=key->link;
        
    }
    if (key==NULL)
        printf("%d is not found the list .",k);
}

void insert(){
    int n,pos,c=1;
    printf("Enter the elements that you want to insert : ");
    scanf("%d",&n);
    printf("Enter the postion where are you want to insert : ");
    scanf("%d",&pos);
    struct node *temp=start;
    struct node *p=(struct node*)malloc(sizeof(struct node));
    p->data=n;
    p->link=NULL;
    if (pos==1)
    {
        p->link=start;
        start=p;
    }else{
        //temp=start;
        while ((c<pos-1)&&temp->link!=NULL)
        {
            temp=temp->link;
            c++;
        }
        p->link=temp->link;
        temp->link=p;
    }
    display();

}
void delete(){
    int pos,c=1;
    printf("Enter the postion where are you want to delete : ");
    scanf("%d",&pos);
    struct node *p=(struct node*)malloc(sizeof(struct node));
    struct node *temp=start;
    if (pos==1)
        start=start->link;
    else{
    while (c<pos-1 && temp->link!=NULL)
    {
        temp=temp->link;  
        c++;      
    }
    if (temp->link!=NULL)
        temp->link=temp->link->link;        
    } 
    display();
    
}

void delete_key(){
if (check()==1)
{
    int key;
    struct node *p,*temp;
    printf("Enter the element that is you want to delete : ");
    scanf("%d",&key);
    temp=p=start;
    if (temp->data==key){
    start=start->link;
    }else{
    temp=temp->link;
    // p=start;
    while (temp!=NULL && temp->data!=key){
        p=temp;
        temp=temp->link;    
    }
    if(temp!=NULL)
        p->link=temp->link; 
    else
        printf(" %d elements is available in link list\n",key);       
    }
}else
    printf("This link list is empty\n");


display();    
}

void delete_before(){

    int key;
    struct node *p,*temp;
    printf("Enter the element, for delete before this item : ");
    scanf("%d",&key);
    temp=p=start;
    if (temp->data==key){
    printf("No node before this key.\n");
    }else if(temp->link->data==key){
            start=temp->link;
    }else{
    temp=temp->link->link;
    while (temp!=NULL && temp->data!=key){
        p=p->link;
        temp=temp->link;      
    }
    if(temp!=NULL)
        p->link=temp; 
    else
        printf(" %d elements is available in link list\n",key);       
    }    

display();    
}

void delete_after(){

    if(check()==1){
    int key;
    struct node *temp;
    printf("Enter the element,for delete after this item : ");
    scanf("%d",&key);
    temp=start;
    while (temp->link!=NULL && temp->data!=key){
        temp=temp->link;    
    }
    if(temp->link!=NULL)
        temp->link=temp->link->link; 
    else
        printf(" %d elements is available in link list\n",key); 
    }   
    else
    printf("This link list is empty\n");

    display();    
}

void insert_before(){
    int key,n;
    struct node *t;
    printf("Enter the elements that you want to insert : ");
    scanf("%d",&n);
    printf("Enter the key element : ");
    scanf("%d",&key);
    struct node *p=(struct node*)malloc(sizeof(struct node));
    p->data=n;
    p->link=NULL;
    struct node *temp=start;
    if (temp->data==key)
    {
        p->link = start;
        start=p;
    }else
    {
    temp=temp->link;
    t=start;
    while (temp!=NULL && temp->data!=key)
    {
        t=temp;
        temp=temp->link;
    }    
    if (temp!=NULL)
    {
    p->link=t->link;
    t->link=p;
    }else
    printf("%d is not in the link list.\n",key);
    }
    
    display(); 
}
void insert_after(){
    int key,n;
    printf("Enter the elements that you want to insert : ");
    scanf("%d",&n);
    printf("Enter the key element : ");
    scanf("%d",&key);
    struct node *p=(struct node*)malloc(sizeof(struct node));
    p->data=n;
    p->link=NULL;
    struct node *temp=start;

    while (temp!=NULL && temp->data!=key)
    {
        temp=temp->link;
    }   
    if (temp!=NULL)
    {
    p->link=temp->link;
    temp->link=p;
    }else
    printf("%d is not in the link list.\n",key);
    
    
    display(); 
}

void sorting(){
    struct node *t1,*t2;
    t1=start;
    while (t1!=NULL)
    {
        t2=t1->link;
        while (t2!=NULL)
        {
            if (t1->data>t2->data)
            {
                int temp=t1->data;
                t1->data=t2->data;
                t2->data=temp;
            }
            t2=t2->link;
        }
        t1=t1->link;
    }
    printf("After sorting the elements.\n");
    display();
}

void reverse()
{
struct node *t=start;
int i=0,a[20];
while (t!=NULL)
{
a[i]=t->data;
t=t->link;   
i++; 
}
t=start;
while (t!=NULL)
{
    t->data=a[i-1];
    t=t->link;
    i--;
}

display();
}

void reverse_node()
{
    struct node *t1,*t2,*prev;
    t1=start;
    prev=NULL;
    while (t1!=NULL)
    {
        t2=t1->link;
        t1->link=prev;
        prev=t1;
        t1=t2;
    }
    start=prev;

    display();
}

void print_last_n_node(){
    int n,i=1;
    printf("Enter integer from where you want to print : ");
    scanf("%d",&n);
    struct node *p;
    p=start;
    while (i<n && p!=NULL)
    {
        p=p->link;
        i++;
    }
    if (p!=NULL)
    {
        printf("The list from n th term to last: ");
        while (p!=NULL)
        {
            printf(" %d ",p->data);
            p=p->link;
        } 
    }else
        printf("There is no elements after %dth position.",n);
    
}

void delete_duplicate(){
sorting();
struct node *p=start;
while (p->link!=NULL)
{
    if (p->data == p->link->data)
    {
        p->link=p->link->link;
    }
    p=p->link;  
}
printf("After removing duplicate elements.\n");
display();
}



// void insert_key(){
// int key,n;
//     printf("Enter the elements that you want to insert : ");
//     scanf("%d",&n);
//     printf("Enter the key element : ");
//     scanf("%d",&key);
//     struct node *p=(struct node*)malloc(sizeof(struct node));
//     p->data=n;
//     p->link=NULL;
//     struct node *temp=start;
//     while (temp!=NULL && temp->data!=key)
//     {
//         temp=temp->link;
//     }
//     if (temp!=NULL)
//     {
//     p->link=temp->link;
//     temp->link=p;
//     }else
//     printf("%d is not in the link list.\n",key);
    
//     display(); 
// }

// void count(){
//     int count=0;
//     struct node *c=(struct node*)malloc(sizeof(struct node));
//     c=start;
//     while (c!=NULL){
//         c=c->link;
//         count++;
//     }
//     printf("The number of node is- %d",count);
// }