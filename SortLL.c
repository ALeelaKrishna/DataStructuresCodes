#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
}*start=NULL,*current=NULL,*previous=NULL;

void Insertion(int value)
{
	current=start;
	previous=NULL;
	struct node* newnode=malloc(sizeof(struct node));
	newnode->data= value;
	newnode->next=NULL;
	if(current==NULL)
	{
		start=newnode;
	}
	else
	{
	   while(1)
	   {
	   	if(current==NULL)
	   	 {
	   	  previous->next=newnode;
	   	  break;
	   	 }
	   	
	   	else if((current->data)<(newnode->data))
	   	 {
	   	 	previous=current;
	   	 	current=current->next;
		 }
		 else
		  {
		  	if(previous==NULL)
		  	 {
		  	 	newnode->next=current;
		  	 	start=newnode;
		  	 	break;
			 }
			 
			  else
			   {
			   	previous->next=newnode;
			   	newnode->next=current;
			   	break;
			   }
			  
		  }
	   }
	}
}

void display()
{
	current=start;
	while(current!=NULL)
	{
		printf("%d->",current->data);
		current=current->next;
	}
	
}	



int main(void)
{
int opt,i=1,x,r;
while(1)
{
	printf(" \n 1 to insert \n 2 to display list\n 3 to exit");
		scanf("%d",&opt);
	switch(opt)
	{
		case 1: printf("enter value to be inserted:");
			    scanf("%d",&x);
			    Insertion(x);
			    break;
	   
	   case 2: display();
	           break;	    
	   
	   case 3: exit(0);
	           break;
	        
	}
	}
return(0);		
}

