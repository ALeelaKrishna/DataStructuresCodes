#include<stdio.h>
int top=-1;
int max_size;
void push(int a[],int x)
{
 if(top>=max_size-1)
 {
  printf("STACK IS FULL\n");
 }
 else
 {
 top=top+1;
 a[top]=x;
 }
}
int pop(int a[])
{
 int x;
 if(top<0)
 {
  printf("STACK IS EMPTY\n");
 }
 else
 {
 x=a[top];
 top=top-1;
 return(x);
 }
}
void status(int a[])
{
 if(top<0)
  printf("STACK IS EMPTY\n");
 else if(top==max_size)
   printf("STACK IS FULL\n");
 else
   printf("number of slots available in the stack is %d\n",max_size-1-top);
 }
int main(void)
{ 
 int o,i=0,x,j;
 printf("enter the max_size of array\n");
 scanf("%d",&max_size);
 int a[max_size-1];
while(i==0)
{
printf("enter the option you want to select\n1.To Push a number\n2.To Pop a number\n3.To display the stack\n4.To show the status\n5.To exit");
 scanf("%d",&o);
switch(o)
 {
  case 1: 
         printf("enter the element to be pushed\n");
         scanf("%d",&x);
         push(a,x);
         break;
  case 2:
         printf("%d",pop(a));
         break;
  case 3:
          if(top<0)
            printf("STACK IS EMPTY\n");
        else
         {
         printf("STACK IS\n");
         for(j=0;j<=top;j=j+1)
          printf("%d\t",a[j]);
         } 
        break;
  case 4:
          status(a);
         break;
  case 5: 
         i=i+1;
         break;

 }
}
return(0);
}
