#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next_ptr;
struct node *previous_ptr;
};
struct node *rear=NULL;
struct node *current;
void Enqueue(value)
{
 struct node *new_node=malloc(sizeof(struct node));
 
 new_node->data=value;
 
 if(rear==NULL)
  { 
    rear=new_node;
    rear->next_ptr=rear;
    rear->previous_ptr=rear;
  }
 else
  {
    new_node->previous_ptr=rear;
    new_node->next_ptr=rear->next_ptr;
    rear->next_ptr=new_node;
    new_node->next_ptr->previous_ptr=new_node;
    rear=new_node;
  }
}
void Display()
{

  current=rear->next_ptr;
 if(current==NULL)
  {
   printf("No element in the queue");
  }
 if(current==rear)
  {
   printf("%d\n",rear->data);
  }
 else
  {
    while(current!=rear)
     {
      printf("%d<-->",current->data);
      current=current->next_ptr;
     }
    printf("%d\n",rear->data);
  }
}

void Dequeue()
{
 current=rear->next_ptr;
 if(current==NULL)
{
 printf("no element is present");
}
 if(current==rear)
  {
   free(current);
  }
 else
  {
  rear->next_ptr=current->next_ptr;
  current->next_ptr->previous_ptr=rear;
  current=current->next_ptr;
  
  }
}
int main(void)
{
int opt,value;
do
{
printf("\nEnter the option\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\n");
scanf("%d",&opt);
switch(opt)
 {
 case 1:printf("\nenter the number you want to enqueue\n");
        scanf("%d",&value);
        Enqueue(value);
        break;
 case 2:Dequeue();
        break;
 case 3:Display();
        break;
 case 4:exit(0);
        break;
 }

}while(1);
return(0);
}
