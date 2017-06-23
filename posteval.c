#define SIZE 50
#include<stdio.h>            /* Size of Stack */
#include <ctype.h>
#include<math.h>
int s[SIZE];
int top=-1;       /* Global declarations */

void push(int elem)
{                       /* Function for PUSH operation */
 s[++top]=elem;
}

int pop()
{                      /* Function for POP operation */
 return(s[top--]);
}

void main()
{                         /* Main Program */
 char pofx[50],ch;
 int i=0,op1,op2;
 printf("\n\nRead the Postfix Expression ? ");
 scanf("%s",pofx);
 while( (ch=pofx[i]) != '\0')
 {
  if((ch>=48)&&(ch<=57))    
   push(ch-'0'); /* Push the operand */
  else
  {        /* Operator,pop two  operands */
   op2=pop();
   op1=pop();
   switch(ch)
   {
   case '+':push(op1+op2);break;
   case '-':push(op1-op2);break;
   case '*':push(op1*op2);break;
   case '/':push(op1/op2);break;
   case '^':push(pow(op1,op2));break;
   }
  }
i=i+1;
 }
 printf("\n Given Postfix Expn: %s\n",pofx);
 printf("\n Result after Evaluation: %d\n",s[top]);
}
