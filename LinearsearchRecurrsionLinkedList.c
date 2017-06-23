#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node *next_ptr;
};
struct node *head1=NULL;
struct node *Current=NULL;
void Insert(value)
{
 struct node *new_node=malloc(sizeof(struct node));
 
 new_node->data=value;
 
 if(head1==NULL)
  { 
    head1=new_node;
    head1->next_ptr=NULL;
    Current=head1;
  }
 else
  {
    Current->next_ptr=new_node;
    Current=new_node;
    Current->next_ptr=NULL;
  }
}
void Display(struct node *head)
{
 if(head==NULL)
  {
   printf("No element in the List");
  }
 else
  {
    while(head!=NULL)
     {
      printf("%d->",head->data);
      head=head->next_ptr;
     }
    printf("NULL");
  }
}
void Search(int x,struct node *head)
{
 if(head==NULL)
  {
   printf("Iam not here");
  }
 else if(x==head->data)
  {
    printf("I am IN");
  }
 else
  Search(x,head->next_ptr);
}
int main(void)
{
int opt,value,x;

do
{
printf("\nEnter the option\n1.List1 Entry\n2.Display First Linked List\n3.Search\n4.Exit\n");
scanf("%d",&opt);
switch(opt)
 {
 case 1:printf("\nenter the number you want to insert\n");
        scanf("%d",&value);
        Insert(value);
        break;
   
 case 2:Display(head1);
        break;
 case 3:printf("Enter an element to search\n");
        scanf("%d",&x);
        Search(x,head1);
        break;
 case 4:exit(0);
        break;
 }

}while(1);
return(0);
}


