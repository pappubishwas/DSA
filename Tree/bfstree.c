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
void insertion(struct node *);
struct node *deletion();
void bfs();
int main()
{
    create(20);
    create(10);
    create(30);
    create(5);
    create(15);
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
    struct node *temp;
    struct stack *n;
    insertion(root);
    temp = deletion();
    printf("Bfs of tree: ");
    while (temp != NULL)
    {
        if (temp->left != NULL)
            insertion((temp->left));
        if (temp->right != NULL)
            insertion((temp->right));
        printf("%d  ", temp->data);
        temp = deletion();
    }
}

void insertion(struct node *k)
{
    struct stack *top = start, *p;
    p = (struct stack *)malloc(sizeof(struct stack));
    p->address = k;
    p->next = NULL;
    if (start == NULL)
        start = p;
    else
    {
        while (top->next != NULL)
        {
            top = top->next;
        }

        top->next = p;
    }
}

struct node *deletion()
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
