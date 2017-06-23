#include<stdio.h>
#include<stdlib.h>

struct node{
 struct node *right;
 struct node *left;
 int data;
};
struct node *root=NULL;
struct node *current=NULL;
struct node *previous=NULL;
void insert(int value)
{
struct node *new_node=malloc(sizeof(struct node));
new_node->data=value;
new_node->left=NULL;
new_node->right=NULL;
 if(root==NULL)
  root=new_node;
 else
  {
   current=root;
   while(1)
    {
     if(new_node->data<current->data)
      {
       if(current->left==NULL)
        {
          current->left=new_node;
          break;
        }
      current=current->left;
      }
      else if(new_node->data>current->data)
      {
       if(current->right==NULL)
        {
         current->right=new_node;
         break;
        }
        current=current->right;
      }
     }
    }
  }
  
void Search(struct node *root,int k)
{
 current=root;
 while(1)
 {
  if(current->data==k)
  {
   printf("Match Found\n");
   break;
  }
   else if(current->left==NULL)
   {
   printf("Match not found\n");
   break;
   }
   else if(current->right==NULL)
   {
   printf("Match not found\n");
   break;
   }
  else if(current->data<k)
    current=current->right;
  else if(current->data>k)
    current=current->left;

  }
 }

void InOrderDisplay(struct node *root)
{
   if(root!=NULL)
    {
     InOrderDisplay(root->left);
      printf("%d\t",root->data);
      InOrderDisplay(root->right);
      }
}

void PreOrderDisplay(struct node *root)
{
   if(root!=NULL)
    {
     printf("%d\t",root->data);
     PreOrderDisplay(root->left);
     PreOrderDisplay(root->right);
      }
}

void PostOrderDisplay(struct node *root)
{
   if(root!=NULL)
    {
     PostOrderDisplay(root->left);
      PostOrderDisplay(root->right);
      printf("%d\t",root->data);
      }
}
int Maximum(struct node *root)
{
 current=root;
 if(current->right!=NULL)
 {
 while(current->right!=NULL)
  {
   current=current->right;
  }
  return(current->data);
 }
 
 else
  return(current->data);
 } 
int Minimum(struct node *root)
{
 current=root;
 if(current->left!=NULL)
 {
 while(current->left!=NULL)
  {
   current=current->left;
  }
  return(current->data);
 }
 else
  return(current->data);
 }
 
void Successor(struct node *root,int suc)
{
 current=root;
 while(1)
 {
  if(current->data==suc)
   { 
    if(current->right!=NULL)
      {
       current=current->right;
       printf("%d",Minimum(current));
       break;
      }
     else
     {
      
     }
    }
  else if(current->data<suc)
  { 
    previous=current;
    current=current->right;
  }
  else if(current->data>suc)
   {
    previous=current;
    current=current->left;
   }
}
}
void Predecessor(struct node *root,int pre)
{
 current=root;
 while(1)
 {
  if(current->data==pre)
   { 
    if(current->left!=NULL)
      {
       current=current->left;
       printf("%d",Maximum(current));
       break;
      }
    }
  else if(current->data<pre)
  { 
    previous=current;
    current=current->right;
  }
  else if(current->data>pre)
   {
    previous=current;
    current=current->left;
   }
}
}
int main(void)
{
 int option,val,key,pre,suc,x,y;
 
 while(1)
  {
 printf("Enter the option you want to perform\n1.Insert\n2.Search\n3.Inorder Display\n4.Preorder Display\n5.Postorder Display\n6.Exit\n7.Maximum\n8.Minimum\n9.Successor\n10.Predecessor\n");
 scanf("%d",&option);
 switch(option)
   {
    case 1:printf("\nEnter the number you want to insert\n");
           scanf("%d",&val);
           insert(val);
           break;
     
    case 2:printf("\nEnter the number you want to search\n");
           scanf("%d",&key);
           Search(root,key);
           break;
   
   case 3:InOrderDisplay(root);
          printf("\n");
          break;   
  
   case 4:PreOrderDisplay(root);
          printf("\n");
           break;   
  
   case 5:PostOrderDisplay(root);
          printf("\n");
          break;
          
   case 6:exit(0);
          break;
   
   case 7:x=Maximum(root);
          printf("%d\n",x);
          break;
          
   case 8:y=Minimum(root);
          printf("%d\n",y);
          break;
         
   case 9:printf("\nEnter the number you want to find the successor\n");
           scanf("%d",&suc);
          Successor(root,suc);
          break;
   
   case 10:printf("\nEnter the number you want to find the predecessor\n");
           scanf("%d",&pre);
           Predecessor(root,pre);
          break;
 }
  }
 return(0);
}
 
