/* program to check if a tree is height-balanced or not */
#include <stdio.h>
#include <stdlib.h>
#define bool int

struct node
{
    int data;
    struct node *left;
    struct node *right;
}*root=NULL;


int height(struct node *node);


bool isBalanced(struct node *node)
{
    int lh;   /* for height of left subtree */
    int rh;   /* for height of right subtree */

    if (node == NULL)
        return 1;

    lh = height(node->left);
    rh = height(node->right);

    if (abs(lh - rh) <= 1 && isBalanced(node->left) && isBalanced(node->right))
        return 1;
    return 0;
}



int max(int a, int b)
{
    return (a >= b) ? a : b;
}



int height(struct node *node)
{
    if (node == NULL)
        return 0;

    return 1 + max(height(node->left), height(node->right));
}



void create(int val)
{
    struct node *new, *parent, *node;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = val;
    new->left = NULL;
    new->right = NULL;
    node = root;
    parent = NULL;
    if (root == NULL)
    {
        root = new;
    }
    else
    {
        while (node != NULL)
        {
            parent = node;
            if (val < node->data)
                node = node->left;
            else
                node = node->right;
        }
        if (val < parent->data)
        {
            parent->left = new;
        }
        else
            parent->right = new;
    }
}


int main()
{

    create(40);
    create(20);
    create(10);
    create(30);
    create(60);
    create(45);
    create(41);
    create(70);
    if (isBalanced(root))
        printf("Tree is AVL");
    else
        printf("Tree is not AVL");


    return 0;
}