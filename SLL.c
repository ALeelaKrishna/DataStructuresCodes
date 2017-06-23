#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
} *start=NULL, *new_node,*current;

void begin(value)
{
	new_node= (struct node*) malloc(sizeof(struct node));
	new_node->data=value;
	new_node->next=NULL;
	if (start==NULL)
	{
		start=new_node;
					
	}
	else
	{
		new_node->next=start;
		start=new_node;
	}
}

void middle(num,value)
{
	new_node=malloc(sizeof(struct node));
	new_node->data=value;
	new_node->next=NULL;
	
	current=start;
	
	while(current->data != num)
	{
		current=current->next;
	}
	new_node->next= current->next;
	current->next=new_node;
}

void end(value)
{
	
	new_node= malloc(sizeof(struct node));
	new_node->data=value;
	new_node->next=NULL;
	
	current=start;
	if (current==NULL)
	{
		start=new_node;
	}
	else
	{
		while(current->next !=NULL)
		{
			current=current->next;
		}
		current->next=new_node;
	}
}

int deletemiddle(value)
{
	struct node *prev;
	current=start;
	while(current != NULL)
	{
		if(current->data == value)
		{
			if(start==current)// only one node
			{
				start=current->next;
				free(current);
				return 0;
			}
			else // more than one node
			{
				prev->next=current->next;
				free(current);
				return 0;
			}
		}
		else
		{
			prev=current;
			current=current->next;
			
		}
		
	}
}

int deleteend()
{
	struct node *prev;
	current=start;
	
	while(current->next != NULL)
	{
		prev=current;
		current=current->next;
	}
	
	if(start==current)// only one node
	{
		start=current->next;
		free(current);
		return 0;
	}
	
	prev->next=NULL;
	free(current);
	return 0;
}

int deletebegin()
{
	current=start;
	start=current->next;
	free(current);
	return 0;
}

void display()
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
			printf(" %d ->",current->data);
			current=current->next;
		}
		printf("NULL \n");
	}
}

main()
{
	
	while(1)
	{
		int ch;
		printf("Enter the choice \t 1.Begin \t2. End \t3. Middle \t 4. deletemiddle \t 5. deleteend \t 6. deletestart \t 7.exit \n ");
		scanf("%d",&ch);
		switch (ch)
		{	int value, num;
			case 1: 
					printf("Enter the value to insert at the begining:");
					scanf("%d",&value);
					begin(value);
					display();
					break;
				case 2: 
						printf("Enter the value to insert at the End:");
						scanf("%d",&value);
						end(value);
						display();
						break;
					case 3:
							//int num;
							printf("After which data do you want to insert:");
							scanf("%d",&num);
							printf("Enter the value to insert at the middle");
							scanf("%d",&value);
							middle(num,value);
							display();
							break;
						case 4:
								printf("Enter the number to be deleted:");
								scanf("%d",&value);
								deletemiddle(value);
								display();
								break;
							case 5: 
									deleteend();
									display();
									break;
									case 6: 
											deletebegin();
											display();
											break;
										case 7: exit(0);
			
		}
	}// end of while
}
