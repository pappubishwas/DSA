#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left, *right;

} *root = NULL;
struct stack
{
    struct node *address;
    struct stack *next;
} *start = NULL;

void create(int);
void push(struct node *);
struct node *pop();
void bfs();
int main()
{
    create(20);
    create(10);
    create(30);
    create(5);
    create(15);
    create(40);
    create(25);
    create(50);
    bfs();
}

void create(int k)
{
    struct node *new, *parent, *node;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = k;
    new->left = NULL;
    new->right = NULL;
    if (root == NULL)
        root = new;
    else
    {
        node = root;
        while (node != NULL)
        {
            parent = node;
            if (k > node->data)
                node = node->right;
            else
                node = node->left;
        }
        if (k > parent->data)
            parent->right = new;
        else
            parent->left = new;
    }
}

void bfs()
{
    struct node *p = root, *temp, *t;
    struct stack *n=start;
    push(root);
    temp = pop();
    printf("DFS of tree(preorder): ");
    while (temp != NULL)
    {
        if (temp->right != NULL)
            push((temp->right));
        if (temp->left != NULL)
            push((temp->left));
        printf("%d  ", temp->data);
        temp = pop();
    }

    // push(root);
    // temp = root;
    // printf("\nDFS of tree: ");
    // while (n != NULL)
    // {
    //     if (temp->left != NULL)
    //     {
    //         push((temp->left));
    //         temp = temp->left;
    //     }
    //     else if (temp->right != NULL)
    //     {
    //         t=pop();
    //         printf("%d  ",t->data);
    //         push((temp->right));
    //         temp = temp->right;
    //     }
    //     if (temp->left == NULL && temp->right == NULL)
    //     {
            
    //         t = pop();
    //         printf("%d  ",t->data);
    //         if (t->right != NULL){
    //             push(t->right);
    //             temp = t->right;
    //         }
    //     }
    // }
}



void push(struct node *k)
{
    struct stack *top = start, *p;
    p = (struct stack *)malloc(sizeof(struct stack));
    p->address = k;
    p->next = NULL;
    if (start == NULL)
        start = p;
    else
    {
        start = p;
        p->next = top;
    }
}

struct node *pop()
{
    struct node *n = NULL;
    if (start == NULL)
    {
        n = NULL;
        return n;
    }
    else
    {
        n = start->address;
        start = start->next;
        return n;
    }
}