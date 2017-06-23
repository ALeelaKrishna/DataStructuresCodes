// Reversal of linked list using iterative method and recusive method


#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
} *start, *new_node, *current;

insert(num)
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

void Fdisplay(struct node *current) //  Print elements of a linked list in forward order using recursion
{
	if(current == NULL) 
 	{
	 	return;
 	}
 	printf("%d->",current->data);
 	Fdisplay(current->next);
}

void Rdisplay(struct node *current) // Print elements of a linked list in reverse order using recursion
{
 if(current == NULL) 
 {
 	return;
 }

 Rdisplay(current->next);
 printf("%d->",current->data);
}

void Ireverse() // iterative reverse
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

void Rreverse(struct node *prev, struct node *current) // recursive reverse
{
	if(current)
	{
		Rreverse(current,current->next);
		current->next=prev;
	}
	else
	{
		start=prev;
	}

}

main()
{
	int op, num;
	while(1)
	{
		printf("Enter your choice: 1. Insert 2. IReverse \t 3. Rreverse \t 4. Forward display \t 5. Reverse display \t 6.Exit");
		scanf("%d",&op);
		
		switch(op)
		{
			case 1:
				printf("Enter the number:");
				scanf("%d",&num);
				insert(num);
				display();
				break;
				case 2:
					Ireverse(); //iterative reverse
					display();
					break;
					case 3:
						Rreverse(NULL,start); // recursive reverse
						display();
						break;
						case 4:
							Fdisplay(start); // forward display using recusion
							break;
							case 5:
								Rdisplay(start); // reverse display using recusion
								break;
								case 6: 
									exit(0); // exit
		}
	}
}
