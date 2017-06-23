#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int n,top=-1;
void push(char x,char a[])
{
	top=top+1;
	a[top]=x;

}

char pop(char a[])
{
char x; 
	x=a[top];
	top--;
	return(x);
}

int priority(char symbol)
{
	if (symbol=='^')
		return(5);
	else if(symbol=='*')
		return(4);
	else if(symbol=='/')
		return(4);
	else if(symbol=='+')
		return(2);
	else if(symbol=='-')
		return(2);
        else
             return(-1);
        
}


int main()
{
int i=0;
char token,element,a[30];
printf("Enter infix expression\n");
scanf("%s",a);
char s[strlen(a)];

	while((token=a[i])!='\0')
	{
		if(token==40)//opening brace
			push(token,s);
		
		else if(token==41)//closing brace
			while((element=pop(s))!=40)
				printf("%c",element);
		else if((token >=65)&&(token<=122)&&(token!=94))//operands
			printf("%c",token);
		
		else
		{
			while(priority(token)<=priority(s[top]))
				printf("%c",pop(s));
			push(token,s);
		}
        
i=i+1;
	}

while(top>=0)
	 printf("%c",pop(s));
printf("\n");
	 
return(0);
}
				
				
