#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *nptr;
};
struct node *current;
struct node *previous=NULL;
struct node *start=NULL;

void insert(value)
{
  struct node *new_node=malloc(sizeof(struct node));
  current=start;
 if(current==NULL)
 {
  new_node->data=value;
  new_node->nptr=NULL; 
  start=new_node;
 }
else
 {
 while(current->nptr!=NULL)
  { 
  
   current=current->nptr;
  }
  new_node->data=value;
  new_node->nptr=NULL; 
  current->nptr=new_node;
}
}
void delete()
{
  if(start->nptr==NULL)
   {
    start=NULL;
   }
  else if(start==NULL)
   {
    printf("NO ELEMENT TO DELETE");
   }
  else
   {
    current=start;
   while(current->nptr!=NULL)
   {
    previous=current;
    current=current->nptr;
   }
   previous->nptr=NULL;
  }
 }
void display()
{
 current=start;
 if(start==NULL)
  {
   printf("no element is present in stack");
  }
 else
  {
   while(current!=NULL)
    {
     printf("%d->",current->data);
     current=current->nptr;
    }
   printf("NULL");
  }
}
int main(void)
{
 int i,opt,value;
 do
{
 printf("\nEnter the option you want to enter\n1.Insertion\n2.Deletion\n3.Display\n");
 scanf("%d",&opt);
 switch(opt)
{
  case 1:printf("enter an element you want to enter\n");
         scanf("%d",&value);
         insert(value);
         break;
  case 2:delete();
         break;
  case 3:display();
     break;
  }
}while(i<=3);
return(0);
}

