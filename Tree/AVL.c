/* program to check if a tree is height-balanced or not */
#include <stdio.h>
#include <stdlib.h>
#define bool int

/* A binary tree node has data, pointer to left child
 and a pointer to right child */
struct node
{
    int data;
    struct node *left;
    struct node *right;
}*root=NULL;

/* Returns the height of a binary tree */
int height(struct node *node);

/* Returns true if binary tree with root as root is height-balanced */
bool isBalanced(struct node *node)
{
    int lh; /* for height of left subtree */
    int rh; /* for height of right subtree */

    /* If tree is empty then return true */
    if (node == NULL)
        return 1;

    /* Get the height of left and right sub trees */
    lh = height(node->left);
    rh = height(node->right);

    if (abs(lh - rh) <= 1 && isBalanced(node->left) && isBalanced(node->right))
        return 1;

    /* If we reach here then tree is not height-balanced */
    return 0;
}

/* UTILITY FUNCTIONS TO TEST isBalanced() FUNCTION */

/* returns maximum of two integers */
int max(int a, int b)
{
    return (a >= b) ? a : b;
}

/*  The function Compute the "height" of a tree. Height is the
 number of nodes along the longest path from the root node
 down to the farthest leaf node.*/
int height(struct node *node)
{
    /* base case tree is empty */
    if (node == NULL)
        return 0;

    /* If tree is not empty then height = 1 + max of left
     height and right heights */
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

