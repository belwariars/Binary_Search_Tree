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
	struct node* root = (struct node*)malloc(sizeof(struct node));
	root->data = data;
	root->left = NULL;
	root->right = NULL;
	
	return root;
}

struct node* insert(struct node* root, int data)
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

struct node* searchnode(struct node* root, int data)
{
	if(root == NULL || root->data == data)
	{
		return root;
	}
	
	if(data < root->data)
	{
		return searchnode(root->left, data);
	}
	else if(data > root->data)
	{
		return searchnode(root->right, data);
	}
}

void inorder(struct node* root)
{
	if(root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

struct node* minr(struct node* root)
{
	while(root->left != NULL)
	{
		root = root->left;
	}
	
	return root;
}

struct node* deletenode(struct node* root, int data)
{
	if(root == NULL)
	{
		return root;
	}
	
	if(data < root->data)
	{
		root->left = deletenode(root->left, data);
	}
	else if(data > root->data)
	{
		root->right = deletenode(root->right, data);
	}
	else
	{
		if(root->left == NULL)
		{
			struct node* temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL)
		{
			struct node* temp = root->left;
			free(root);
			return temp;
		}
		else
		{
			struct node* temp = minr(root->right);
			root->data = temp->data;
			deletenode(root->right, temp->data);
		}
	}
	
	return root;
}

int main()
{
	struct node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
 
    printf("Inorder traversal of the given tree \n");
    inorder(root);
 
    printf("\nDelete 20\n");
    root = deletenode(root, 20);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
 
    printf("\nDelete 30\n");
    root = deletenode(root, 30);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
 
    printf("\nDelete 50\n");
    root = deletenode(root, 50);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
	return 0;
}
