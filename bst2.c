#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

//Height
int height(struct node *root)
{
	int x,y;
	if(root==NULL)
		return 0;
	x=height(root->left);
	y=height(root->right);
	if(x>y)
		return x+1;
	else
		return y+1;
}

//Insert

struct node * insert(struct node *r,int x)
{
	if(r==NULL)
	{
		struct node *new=malloc(sizeof(struct node));
		new->data=x;
		new->left=new->right=NULL;
		return new;
	}
	if(x>r->data)
		r->right=insert(r->right,x);
	if(x<r->data)
		r->left=insert(r->left,x);
	return r;
}

//Max 
struct node * max(struct node *r)
{
	if(r==NULL)
		return r;
	if(r->right)
		return(max(r->right));
	else
		return r;
}

//Min
struct node * min(struct node *r)
{
	if(r==NULL)
		return r;
	if(r->left)
		return(min(r->left));
	else
		return r;
}

//Delete
struct node * delete(struct node *r,int x)
{
	if(x>r->data)
		r->right=delete(r->right,x);
	else if(x<r->data)
		r->left=delete(r->left,x);
	else
	{
		struct node *temp;
		if(r->left&&r->right)
		{
			temp=max(r->left);
			r->data=temp->data;
			r->left=delete(r->left,temp->data);
		}
		else if(!r->left)
		{
			temp=r;
			r=r->right;
			free(temp);
		}
		else
		{
			temp=r;
			r=r->left;
			free(temp);
		}
	}
	return r;
}
		
void inorder(struct node *root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	printf("%d\t",root->data);
	inorder(root->right);
}

//Search
struct node * search(struct node *r,int x)
{
	if(r==NULL)
		return r;
	else if(x>r->data)
		return(search(r->right,x));		
	else if(x<r->data)
		return (search(r->left,x));
	else 
		return r;
}
		
//Successor
struct node *successor(struct node *r,struct node *k)
{
	
	if(k->right)
		return min(k->right);
	else
	{
	struct node *suc=NULL;
	while(r!=NULL)
	{
		if(r->data>k->data)
		{
			suc=r;
			r=r->left;
		}
		else if(r->data<k->data)
			r=r->right;
		else
			break;
	}
	return suc;
	}
}

//Predecessor
struct node *predecessor(struct node *r,struct node *k)
{
	
	if(k->left)
		return max(k->left);
	else
	{
	struct node *suc=NULL;
	while(r!=NULL)
	{
		if(r->data<k->data)
		{
			suc=r;
			r=r->right;
		}
		else if(r->data>k->data)
			r=r->left;
		else
			break;
	}
	return suc;
	}
}


int main(void)
{
	struct node *root=NULL;	
	int ch,x,y;
	struct node *s;
	while(1)
	{
		printf("1-insert\n2-inorder display\n3-delete\n4-height\n5-search\n6-successor\n7-predecessor\n8-exit\n");	
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter the element to insert\n");
				scanf("%d",&x);
				root=insert(root,x);
				break;
			case 2:inorder(root);
				printf("\n");
				break;
			case 3:printf("Enter the element to delete\n");
				scanf("%d",&x);
				root=delete(root,x);
				break;
			case 4:printf("height of tree= %d\n",height(root));
				break;
			case 5:printf("Enter the number to search\n");
				scanf("%d",&x);
				s=search(root,x);
				if(s!=NULL)
					printf("Found\n");
				else
					printf("Not found\n");
				break;
			case 6:printf("Successor of?\n");
				scanf("%d",&x);
				s=successor(root,search(root,x));
				if(s!=NULL)
					printf("Successor is %d\n",s->data);
				else
					printf("No successor\n");
				break;
			case 7:printf("Predecessor of?\n");
				scanf("%d",&x);
				s=predecessor(root,search(root,x));
				if(s!=NULL)
					printf("Predecessor is %d\n",s->data);
				else
					printf("No predecessor\n");
				break;
			case 8:exit(0);
		}
	}
	return 0;
}
			


	
