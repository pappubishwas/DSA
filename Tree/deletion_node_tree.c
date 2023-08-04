#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left, *right;

} *root = NULL;
void search(int);
void create(int);
void deletion(int);
int deleteprecessor(struct node *parent);
void preorder(struct node *node);
int main()
{
    create(10);
    create(12);
    create(11);
    create(7);
    create(15);
    create(5);
    create(8);
    create(9);
    create(2);
    create(1);
    create(3);
    preorder(root);
    deletion(12);
    preorder(root);
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

void deletion(int k)
{
    struct node *temp = root, *parent;
    if (root == NULL)
    {
        printf("The tree is empty.");
    }
    else
    {
        while (temp != NULL)
        {
            if (temp->data < k)
            {
                parent = temp;
                temp = temp->right;
            }
            else if (temp->data > k)
            {
                parent = temp;
                temp = temp->left;
            }
            else
            {
                if (temp->left == NULL && temp->right == NULL)
                {
                    if (temp == parent->left)
                        parent->left = NULL;
                    else
                        parent->right = NULL;
                    free(temp);
                }
                else if (temp->left == NULL)
                {
                    if (parent->left == temp)
                        parent->left = temp->right;
                    else
                        parent->right = temp->right;

                    free(temp);    
                }
                else if (temp->right == NULL)
                {
                    if (parent->left == temp)
                        parent->left = temp->left;
                    else
                        parent->right = temp->left;

                    free(temp);     
                }
                else
                {
                    int key = deleteprecessor(temp);
                    temp->data = key;
                }
                break;
            }
        }
    }
}

int deleteprecessor(struct node *parent)
{
    int k;
    struct node *temp;
    temp = parent;
    parent = parent->right;
    while (parent->left != NULL)
    {
        temp = parent;
        parent = parent->left;
    }
    if (parent->right != NULL)
    {
        temp->right = parent->right;
        k=parent->data;
    }else{
        if(temp->left==parent){
            temp->left=NULL;
            k=parent->data;
        }else{
            temp->right=NULL;
            k=parent->data;
            
        }
    }
    free(parent);
    return k;
}
void preorder(struct node *node)
{
    if (node != NULL)
    {
        printf("%d ", node->data);
        preorder(node->left);
        preorder(node->right);
    }
    else
        return;
}