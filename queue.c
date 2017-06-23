#include<stdio.h>
int front=-1;
int rear=-1;
int max;
void enqueue(int a[],int b);
int dequeue(int a[]);
void display(int a[]);
void status(int a[]);
int main(void)
{
int x;
int a[max-1],b;
printf("Enter the max array size\n");
scanf("%d",&max);

do
{
 printf("Enter the option you want to choose\n");
 printf("1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.STATUS\n5.EXIT\n");
 scanf("%d",&x);
 switch(x){
   case 1: 
     printf("Enter a number you want to enqueue\n");
     scanf("%d",&b);
     enqueue(a,b);
     break;
   case 2:
     dequeue(a);
     break;
   case 3:
     display(a);
     break;
   case 4:
     status(a);
     break;
   case 5:
     printf("EXIT");
     break;
  }     
}while(1);
return(0);
}
void enqueue(int a[],int b)
{
 if(rear==max-1)
 printf("QUEUE IS FULL\n");
 else if((front==-1) && (rear==-1))
 {
  front=front+1;
  rear=rear+1;
  a[rear]=b;
 }
 else
 {rear=rear+1;
 a[rear]=b;
 }
 }
int dequeue(int a[])
{
 int temp;
 if((front==-1) && (rear==-1))
   printf("QUEUE IS EMPTY\n");
 if(front==rear)
  {
   temp=a[rear];
   front=-1;
   rear=-1;
  }
else{
temp=a[front];
front=front+1;
}
return(temp);

}
void display(int a[])
{
 int i;
 for(i=front;i<=rear;i=i+1)
 {
  if((front==-1) && (rear==-1))
   printf("QUEUE IS EMPTY\n");
  else 
   printf("\t%d\t",a[i]);
 }
}
void status(int a[])
{
  if((front==-1) && (rear==-1))
   printf("QUEUE IS EMPTY\n");
  else
   printf("the number of slots available to enqueue are\t%d\n ",max-rear-1);
} 
 

   
