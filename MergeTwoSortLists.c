#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*start=NULL, *new_node, *current;


struct node* insert(struct node *start, int num) // insert at the end in a SLL
{
	struct node* new_node=malloc(sizeof(struct node));
	new_node->data=num;
	new_node->next=NULL;
		
	if(start==NULL)
	{
		start=new_node;
	}
	else
	{
		current=start;
		
		while(current->next != NULL)
		{
			current=current->next;
		}
		current->next=new_node;
		
	}
	
	return start;
		
}


struct node* IterativeSortedMerge(struct node *p1, struct node *p2) 
{
	struct node *start3;
	start3=NULL;
	
	while(p1!=NULL && p2!=NULL)
	{
		if(p1->data < p2->data) 
		{
			start3=insert(start3,p1->data);
			p1=p1->next;
		}
		else if (p2->data < p1->data) 
		{
			start3=insert(start3,p2->data);
			p2=p2->next;
		}
		else if(p1->data == p2->data) 
		{
			start3=insert(start3,p1->data);
			p1=p1->next;
			p2=p2->next;
		}	
		
	}
	while (p1 != NULL) 
	{
		start3=insert(start3,p1->data);
		p1=p1->next;
	}
	while (p2 != NULL) 
	{
		start3=insert(start3,p2->data);
		p2=p2->next;
	}
	
	return start3;
      
}


struct node* RecursiveSortedMerge(struct node* p1, struct node* p2) 
{
  struct node* start3 = NULL;
 
  if (p1 == NULL)  
     return(p2);
  else if (p2==NULL) 
     return(p1);

  if (p1->data <= p2->data)   
  {
  	 start3=insert(start3,p1->data);
     start3->next = RecursiveSortedMerge(p1->next, p2);
  }
  else
  {
  	start3=insert(start3,p2->data);
    start3->next = RecursiveSortedMerge(p1, p2->next);
  }
  return(start3);
}

void display(struct node *start) 
{
	current=start;
	if (current==NULL)
	{
		printf("the list is empty");
	}
	else
	{
		while(current != NULL)
		{
			printf("%d->",current->data);
			current=current->next;
		}
		printf("NULL \n\n");
	}
}


int main(void)
{
  char k;
  int op,num;
  struct node *start1=NULL, *start2=NULL, *start3=NULL;
  while(1)
   {
   printf("Enter your choice: \n 1. Insert into list-1  \n 2. Insert into list-2 \n 3. Iterative Sorted Merge \n 4. Recusive Sorted Merge \n 5. Display List-1 \n 6. Display List-2 \n 7. exit");
   scanf("%d",&op);
    switch(op)
      {
	case 1:
	 printf("enter the number:");
	 scanf("%d",&num);
	 start1=insert(start1,num);
	 display(start1);
	 break;
	
        case 2:
	 printf("enter the number:");
	 scanf("%d",&num);
	 start2=insert(start2,num);
	 display(start2);
	 break;
	
        case 3:
         start3=IterativeSortedMerge(start1,start2); 
 	 display(start3);
	 break;
	
        case 4:
	 start3=RecursiveSortedMerge(start1,start2);
	 display(start3);
	 break;
	
        case 5: 
	 display(start1);
	 break;
	
        case 6:
	 display(start2);
	 break;
	
        case 7:
	 exit(0);
						
				
	}

  }
return(0);
}
