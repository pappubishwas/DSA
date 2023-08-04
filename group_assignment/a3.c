#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int q1[MAX], q2[MAX], q3[MAX];
int front1 = -1, front2 = -1, front3 = -1;
int rear1 = -1, rear2 = -1, rear3 = -1;

void insert(int item, int size)
{
    if (rear1 < size-1)
    {
            if (front1 == -1)
            {
                front1 = 0;
                rear1++;
            }
            else
                rear1++;
            q1[rear1] = item;
        
    }
    else if (rear2 < size-1)
    {
            if (front2 == -1)
            {
                front2 = 0;
                rear2++;
            }
            else
                rear2++;
            q2[rear2] = item;
        
    }
    else
    {
        if (rear3 == size - 1)
        {
            return;
        }
        else
        {
            if (front3 == -1)
            {
                front3 = 0;
                rear3++;
                q3[rear3] = item;
            }
            else
                rear3++;
            q3[rear3] = item;
        }
    }
}



void delete (int size)
{
    int i, j, k;
    if (front1 == size - 1)
        printf("\nThe queue is now empty.");
    else
    {
        front1++;
        for (i = front1; i <= size - 1; i++)
        {
            q1[i - 1] = q1[i];
        }
        q1[size - 1] = q2[front2];
        front1--;
        front2++;
        for (j = front2; j <= size - 1; j++)
        {
            q2[j - 1] = q2[j];
        }
        q2[size - 1] = q3[front3];
        front2--;
        front3++;
        for (k = front3; k <= size - 1; k++)
        {
            q3[k - 1] = q3[k];
        }
        front3--;
        rear3--;
    }
}

void Full(int size)
{
    if (rear3 == size - 1)
        printf("\nAll the queues are full, kindly wait until some people are given the service.");
    else
        printf("\nSpace is available in the queue.");
}
void Empty(int size)
{
    if (front1 == -1)
        printf("\nThe queue is empty and no people available to get the service, kindly wait until some people come.");
    else
        printf("\nThere are people in the queue waiting to receive the service.");
}
void display(int size)
{
    if (front1 == -1)
        printf("\nThe queue is empty.");
    else
    {
        for (int i = front1; i <= rear1; i++)
        {
            printf("%d ", q1[i]);
        }
    }
    if (front2 == -1)
    {
        return;
    }
    else
    {
        for (int j = front2; j <= rear2; j++)
        {
            printf(" %d ", q2[j]);
        }
    }
    if (front3 == -1)
        return;
    else
    {
        for (int k = front3; k <= rear3; k++)
        {
            printf(" %d ", q3[k]);
        }
    }
}
int main()
{
    int choice, size, m, n = 1;
    printf("\nEnter the size of each queue:");
    scanf("%d", &size);
    while (n == 1)
    {
        printf("\n1.To add a person to the queue\n2.To delete a person from the queue\n3.To check if the queue is empty or not\n4.To check if the queue is full or not\n5.To display the people in the queue\n6.Exit");
        printf("\nEnter the operation you want to perform:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the person's ID:");
            scanf("%d", &m);
            insert(m, size);
            break;
        case 2:
            delete (size);
            break;
        case 3:
            Empty(size);
            break;
        case 4:
            Full(size);
            break;
        case 5:
            display(size);
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("\nInvalid choice!");
        }
    }
    return 0;
}