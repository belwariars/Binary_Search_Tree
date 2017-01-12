// Lowest Common Ancestor...

#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;	
};

struct node* createnode(int data)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	
	return temp;
}

struct node *insert(struct node* root, int data)
{
	if(root == NULL)
	{
		return createnode(data);
	}
	
	if(data < root->data)
	{
		root->left = insert(root->left, data);
	}
	else if(data > root->data)
	{
		root->right = insert(root->right, data);
	}
	
	return root;
}

void inorder(struct node *root)
{
	if(root!= NULL)
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

int divideArr(int pre[], int start, int end)
{
	int i;
	for(i=start+1; i<=end; i++)
	{
		if(pre[i] > pre[start])
		return i;
	}
}

struct node* BSTfromPre(int pre[], int start, int end)
{
	if(start > end)
	{
		return NULL;
	}
	
	struct node* root = createnode(pre[start]);
	int div = divideArr(pre, start, end);
	
	root->left = BSTfromPre(pre, start+1, div-1);
	root->right = BSTfromPre(pre, div, end);
	
	return root;
}

int main()
{
   	int pre[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof( pre ) / sizeof( pre[0] );
 
    struct node *root = BSTfromPre(pre, 0, size-1);
 
    printf("Inorder traversal of the constructed tree: \n");
    inorder(root);
 	
  return 0;
}  
