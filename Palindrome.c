#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
} *start1,*start2, *new_node, *current;

void insert(int num)
{       current=start1;
	new_node=malloc(sizeof(struct node));
	new_node->data=num;
	new_node->next=NULL;
	
	if(start1==NULL)
	{
		start1=new_node;
	}
	else
	{     while(current->next!=NULL)
		current=current->next;
             current->next=new_node;
                
	}
}

void InsertatBeginning(int num)
{
	new_node=malloc(sizeof(struct node));
	new_node->data=num;
	new_node->next=NULL;
	
	if(start2==NULL)
	{
		start2=new_node;
	}
	else
	{     new_node->next=start2;
              start2=new_node;
	}

}

void Reverse()
{
 current=start1;
 while(current!=NULL)
  {
    InsertatBeginning(current->data);
    current=current->next;
  }
} 

void PalindromeCheck(struct node *start1,struct node *start2)
{
 while((start1!=NULL)&&(start2!=NULL))
   {
    if(start1->data==start2->data)
     {
       start1=start1->next;
       start2=start2->next;
     }

    else
     {
    printf("Not a palindrome\n");
    exit(0);
     }
    }
    printf("YES it is a palindrome\n");
}

void display(struct node* start)
{
	current=start;
	if(current==NULL)
	{
		printf("the list is empty");
	}
	else
	{
		while(current != NULL)
		{
			printf("%d ->", current->data);
			current=current->next;
		}
		printf("NULL \n\n");
	}
	
}


int main(void)
{
 int option, num;
  while(1)
   {
    printf("Enter your choice: \n1.Insert\n2.Reverse\n3.Exit\n4.Palindrome test\n");
    scanf("%d",&option);
		
    switch(option)
     {
      case 1:
	printf("Enter the number:");
	scanf("%d",&num);
	insert(num);
	display(start1);
	break;
      case 2:
	Reverse();
	display(start2);
	break;
      case 3: 
	exit(0);
      case 4:
        PalindromeCheck(start1,start2);
        break;
      }
 
   }
return(0);
}
