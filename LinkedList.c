#include<stdio.h>
#include<stdlib.h>
int value,number;
struct node
{
 int data;
 struct node *next_ptr;
};

struct node *current;

struct node *previous=NULL;

struct node *start=NULL;

//INSERTION AT END
void IAE(int value)
{
  struct node *new_node=malloc(sizeof(struct node));
  current=start;
 if(current==NULL)
 {
  new_node->data=value;
  new_node->next_ptr=NULL; 
  start=new_node;
 }
else
 {
 while(current->next_ptr!=NULL)
  { 
   current=current->next_ptr;
  }
  new_node->data=value;
  new_node->next_ptr=NULL; 
  current->next_ptr=new_node;
 }
}
//INSERTION AT BEGINNING
void IAB(int value)
{
  struct node *new_node=malloc(sizeof(struct node));
  current=start;
 if(current==NULL)
 {
  new_node->data=value;
  new_node->next_ptr=NULL; 
  start=new_node;
 }
else
 {
  new_node->data=value;
  new_node->next_ptr=current; 
  start=new_node;
  }
}
//INSERTION AT MIDDLE
void IAM(int value,int number)
{
  struct node *new_node=malloc(sizeof(struct node));
  current=start;
 if(current==NULL)
 {
  new_node->data=value;
  new_node->next_ptr=NULL; 
  start=new_node;
 }
else
 {
  while(current->data!=number)
  {
   current=current->next_ptr;
  }
  new_node->data=value;
  new_node->next_ptr=current->next_ptr;
  current->next_ptr=new_node;
 }
}
//DISPLAY
void display()
{
 current=start;
 if(start==NULL)
  {
   printf("no element is present");
  }
 else
 {
 while(current!=NULL)
  {
   printf("%d->",current->data);
   current=current->next_ptr;
  }
 printf("NULL");
 }
}

//DELETION AT END
void DAE()
{
 current=start;
 previous=start;
 if(start==NULL)
  {
   printf("\nno element to delete\n");
  }
  else if(start->next_ptr==NULL)
   {
    start=NULL;
   }
 else
 {
  while(current->next_ptr!=NULL)
   {
     previous=current;
     current=current->next_ptr;
   }
  previous->next_ptr=NULL;
  free(current);
  }
}

//DELETION AT BEGINNING
void DAB()
{
 current=start;
 previous=start;
 if(start==NULL)
  {
   printf("\nno element to delete\n");
  }
 else
 {
  current=current->next_ptr;
  start=current;
 }
}

//DELETION AT MIDDLE
void DAM(int number)
{
 current=start;
 previous=start;
 
 if(start==NULL)
  {
   printf("\nno element to delete\n");
  }
 else
 while(current->data!=number)
   {
     previous=current;
     current=current->next_ptr;
   }
   previous->next_ptr=current->next_ptr;
} 

int main(void)
{
int opt;
do
{
printf("\nEnter the option you want to perform\n1->Insertion at Beginning\n2->Insertion at End\n3->Insertion at Middle\n4->Display\n5->To EXIT\n6->Deletion at End\n7->Deletion at Beginning\n8->Deletion at Middle\n");
scanf("%d",&opt);
switch(opt)
{
 case 1:printf("Enter the value you want to insert\n");
        scanf("%d",&value);
        IAB(value);
        break;

 case 2:printf("Enter the value you want to insert\n");
        scanf("%d",&value);
        IAE(value);
        break;

 case 3:printf("Enter the value you want to insert\n ");
        scanf("%d",&value);
        printf("enter the number after which you want to insert\n");
        scanf("%d",&number);
        IAM(value,number);
        break;
 
 case 4:display();
        break;
 
 case 5:exit(0);
        break;

 case 6:DAE();
        break;

 case 7:DAB();
        break;

 case 8:printf("enter the number which you want to delete\n");
        scanf("%d",&number);
        DAM(number);
        break;
}
}while(1);

return(0);
}

