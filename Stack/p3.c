#include <stdio.h>
#include <stdlib.h>
#define SIZE 8
int array[SIZE];
int top1 = -1;
int top2 = SIZE;

void push1(int data)
{

  if (top1 < top2 - 1)
  {
    top1++;
    array[top1] = data;
  }
  else
  {
    printf("Stack is full");
  }
}

void push2(int data)
{
  if (top1 < top2 - 1)
  {
    top2--;
    array[top2] = data;
  }
  else
  {
    printf("Stack is full.\n");
  }
}

void pop1()
{

  if (top1 >= 0)
  {
    int popped_element = array[top1];
    top1--;

    printf("%d is being popped from Stack 1\n", popped_element);
  }
  else
  {
    printf("Stack is Empty \n");
  }
}

void pop2()
{
  if (top2 < SIZE)
  {
    int popped_element = array[top2];
    top2--;

    printf("%d is being popped from Stack 1\n", popped_element);
  }
  else
  {
    printf("Stack is Empty!\n");
  }
}

void display_stack1()
{
  int i;
  for (i = top1; i >= 0; --i)
  {
    printf("%d ", array[i]);
  }
  printf("\n");
}
void display_stack2() 
{
  int i;
  for (i = top2; i < SIZE; ++i)
  {
    printf("%d ", array[i]);
  }
  printf("\n");
}

int main()
{
  int ar[SIZE];
  int i;
  int num_of_ele, n = 1, o, k;

  while (n == 1)
  {
    printf("Enter the number which operation you want : ");
    scanf("%d", &o);
    switch (o)
    {
    case 1:
    {
      printf("Enter the elements that you want to insert in stack1: ");
      scanf("%d", &k);
      push1(k);
      break;
    }
    case 2:
    {
      printf("Enter the elements that you want to insert in stack2: ");
      scanf("%d", &k);
      push2(k);
      break;
    }
    case 3:
      pop1();
      break;
    case 4:
      pop2();
      break;
    case 5:
      display_stack1();
      break;
    case 6:
      display_stack2();
      break;
    default:
      exit(0);
    }
    printf("If you continue press 1 || otherwise press any key : ");
    scanf("%d", &n);
  }

  return 0;
}
