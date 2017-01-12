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

void modifyBSTutil(struct node* root, int* sum)
{
	if(root == NULL)
		return;
	
	modifyBSTutil(root->right, sum);
	*sum = *sum + root->data;
	root->data = *sum;
	modifyBSTutil(root->left, sum);
}

void modifyBST(struct node *root)
{
	int sum =0;
	modifyBSTutil(root, &sum);
}

int main()
{
   	struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    inorder(root);
    
    modifyBST(root);
    printf("\n\n");
    inorder(root);
 	
  return 0;
}  
