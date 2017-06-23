#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
} *start, *new_node, *current;

void insert(int num)
{       current=start;
	new_node=malloc(sizeof(struct node));
	new_node->data=num;
	new_node->next=NULL;
	
	if(start==NULL)
	{
		start=new_node;
	}
	else
	{     while(current->next!=NULL)
		current=current->next;
             current->next=new_node;
                
	}
}

void display()
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

void IterativeReverse() 
{
	
	struct node *p1, *p2, *p3;
	p1=start;
	p2=p1->next;
	p3=p2->next;
	p2->next=p1;
	p1->next=NULL;
	
	while(p3 != NULL)
	{
		p1=p2;
		p2=p3;
		p3=p3->next;
		p2->next=p1;
		
	}
	start=p2;
	
}

void RecursiveReverse(struct node *prev, struct node *current)
{
	if(current!=NULL)
	{
		Rreverse(current,current->next);
		current->next=prev;
	}
	else
	{
		start=prev;
	}

}

int main(void)
{
 int option, num;
  while(1)
   {
    printf("Enter your choice: \n1.Insert\n2.IterativeReverse\n3.RecursiveReverse\n4.Exit\n");
    scanf("%d",&option);
		
    switch(option)
     {
      case 1:
	printf("Enter the number:");
	scanf("%d",&num);
	insert(num);
	display();
	break;
      case 2:
	IterativeReverse();
	display();
	break;
      case 3:
	RecursiveReverse(NULL,start);
	display();
	break;
      case 4: 
	exit(0);
      }
 
   }
return(0);
}
