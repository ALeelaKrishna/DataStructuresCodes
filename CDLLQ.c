#include<stdio.h>

#include<stdlib.h>
 
int value;
struct node
{

  int data;

  struct node *next_ptr;

  struct node *previous_ptr;
};

struct node *rear=NULL;
struct node *current;
void enqueue(int value)
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
  new_node->next_ptr=rear->next_ptr;
  new_node->next_ptr->previous_ptr=new_node;
  rear->next_ptr=new_node;
  new_node->previous_ptr=rear;
  rear=new_node;
  }
}

void display()
{
 
 if(rear==NULL)
  {
   printf("No element is present in the queue\n");
  }
 else if(rear->next_ptr==rear)
  {
  printf("%d",rear->data);
  }
  else
  {
   current=rear->next_ptr;
   while(current!=rear)
    {
     printf("%d<-->",current->data);
     current=current->next_ptr;
    }
   printf("%d",rear->data);
  }
}

void dequeue()
{ 
 
 if(rear==NULL)
  {
   printf("No element is present in the queue to dequeue\n");
  }
  else if(rear->next_ptr==rear)
  {
  rear=NULL;
  }
  
  else
  {
  current=rear->next_ptr;
  rear->next_ptr=current->next_ptr;
  current->next_ptr->previous_ptr=rear;
  }
}
int main(void)
{

 int opt;
 
 do
{
printf("\nEnter the option you want to perform\n1->Enqueue\n2->Dequeue\n3->Display\n4->Exit\n");
scanf("%d",&opt);
 switch(opt)
{
 case 1:printf("enter the number which you want to enqueue\n");
        scanf("%d",&value);
        enqueue(value);
        break;

 case 2:dequeue();
        break;

 case 3:display();
        break;

 case 4:exit(0);
        break;

 }

}while(1);

return(0);
}
