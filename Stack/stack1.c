#include<stdio.h>
#include<stdlib.h>
#define max 100
struct stack
{
    int s[max];
    int top,top2;
};
// struct stack1
// {
//     int s[max];
//     int top;
// };
void intialize(struct stack *);
void push(struct stack *,int );
void pop(struct stack *,int *);
void print(struct stack*);
void display(struct stack*);
void copy(struct stack*,struct stack*);
void insert_sorted(struct stack*,int x);
void main(){
    struct stack st;
    struct stack st1;
    int b;
    intialize(&st);
    intialize(&st1);
    push(&st,10);
    push(&st,11);
    push(&st,13);
    insert_sorted(&st,12);
    insert_sorted(&st,9);
    insert_sorted(&st,16);
    pop(&st,&b);
    display(&st);
    //copy(&st,&st1);
    //display(&st1);
    //print(&st);
    // printf("%d",st->s[0]);
    // pop(&st,&b);

}

void intialize(struct stack *st){
    st->top=-1;
}
void push(struct stack *st,int n){
    if(st->top==99)
    printf("overflow");

    else {
        st->top++;
        st->s[st->top]=n;
    }

}
void pop(struct stack *st,int *n){
    if(st->top==-1)
    printf("Under flow");
    else{
        *n=st->s[st->top];
        st->top--;
    }
}
void print(struct stack *st){
    printf("%d\n",st->s[0]);
    printf("%d\n",st->s[1]);
}

void display(struct stack *st){
    int b;
    if(st->top==-1)
    return;
    pop(st,&b);
    display(st);
    printf(" %d ",b);
    //display(st);
    push(st,b);
    //display(st);
}
void copy(struct stack *st, struct stack *st1){
    int b;
    if (st->top==-1)
        return;

    pop(st,&b);
    copy(st,st1);
    push(st1,b); 
    push(st,b);   
    
}

void insert_sorted(struct stack *st ,int x){
int b;
if (st->top==-1 || st->s[st->top]<=x) {
push(st,x); 
return;
}
pop(st,&b);
insert_sorted(st,x);
push(st,b);

}

// #include<stdio.h>
// void TOH(int n,char x,char y,char z) {
//    if(n>0) {
//       TOH(n-1,x,z,y);
//       printf("\n%c to %c",x,y);
//       TOH(n-1,z,y,x);
//    }
// }
// int main() {
//    int n=3;
//    TOH(n,'A','B','C');
// }