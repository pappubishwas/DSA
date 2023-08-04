#include <stdio.h>
#include <string.h>
int top = -1, stack[100];
int main()
{
   char a[50], ch;
   int i, op1, op2, res, x;
   void push(int);
   int pop();
   int eval(char, int, int);
   printf("enter a postfix expression:");
   gets(a);
   int size = strlen(a);
   for (i = size - 1; i >= 0; i--)
   {
      ch = a[i];
      if (ch >= '0' && ch <= '9')
         push(ch - '0');
      else
      {
         if (top == 0)
            break;
         op1 = pop();
         op2 = pop();
         res = eval(ch, op1, op2);
         push(res);
      }
   }
   if (top == 0 && a[i] != '\0')
   {
      printf("Given expression is invalid");
   }
   else
   {
      x = pop();
      printf("evaluated value = %d", x);
   }
   return 0;
}
void push(int n)
{
   top++;
   stack[top] = n;
}
int pop()
{
   int res;
   res = stack[top];
   top--;
   return res;
}
int eval(char ch, int op1, int op2)
{
   switch (ch)
   {
   case '+':
      return (op1 + op2);
   case '-':
      return (op1 - op2);
   case '*':
      return (op1 * op2);
   case '/':
      return (op1 / op2);
   }
}