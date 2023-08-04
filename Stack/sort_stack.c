#include <stdio.h>
#include <stdlib.h>
#define max 100
struct stack
{
    int top, s[max];
};
void intialize(struct stack *);
void push(struct stack *, int);
void pop(struct stack *, int *);
void sort(struct stack *, struct stack *);
void print(struct stack *);
int main()
{
    struct stack s1, s2;
    intialize(&s1);
    intialize(&s2);
    push(&s1, 19);
    push(&s1, 11);
    push(&s1, 4);
    push(&s1, 13);
    push(&s1, 10);
    push(&s1, 23);
    sort(&s1, &s2);
    print(&s1);
}

void intialize(struct stack *st)
{
    st->top = -1;
}

void push(struct stack *st, int p)
{
    if (st->top == max - 1)
    {
        printf("Stack is Overflow.");
    }
    else
    {
        st->top++;
        st->s[st->top] = p;
    }
}
void pop(struct stack *st, int *n)
{
    if (st->top == -1)
        printf("Stack is underflow.");
    else
    {
        *n = st->s[st->top];
        st->top--;
    }
}

void sort(struct stack *st1, struct stack *st2)
{
    int t, q;
    while (st1->top != -1)
    {
        pop(st1, &t);
        if (st2->top == -1)
            push(st2, t);
        else
        {
            pop(st2, &q);
            if (t < q)
            {
                push(st2, q);
                push(st2, t);
            }
            else
            {
                push(st1, q);
                push(st1, t);
            }
        }
    }
    while (st2->top != -1)
    {
        pop(st2, &t);
        push(st1, t);
    }
}

void print(struct stack *st)
{
    int t;
    if (st->top == -1)
        return;
    pop(st, &t);
    print(st);
    printf(" %d", t);
    push(st, t);
}