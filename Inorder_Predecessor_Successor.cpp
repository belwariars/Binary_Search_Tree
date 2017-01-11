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

void inorder(struct node* root)
{
	if(root!= NULL)
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

struct node* insert(struct node *root, int data)
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
	if(root==NULL || root->data == data)
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

void inorderSucPre(struct node* root, struct node*& pre, struct node*& suc, int key)
{
	if(root == NULL)
		return;
	
	if(root->data == key)
	{
		if(root->left != NULL)
		{
			struct node* temp = root->left;
			while(temp->right != NULL)
			{
				temp = temp->right;
			}
			
			pre = temp;
		}
		if(root->right != NULL)
		{
			struct node* temp = root->right;
			while(temp->left != NULL)
			{
				temp = temp->left;
			}
			
			suc = temp;
		}
		
		return;
	}
	
	if(key < root->data)
	{
		suc = root;
		inorderSucPre(root->left, pre, suc, key);
	}
	else
	{
		pre = root;
		inorderSucPre(root->right, pre, suc, key);
	}
}

int main()
{
	int key = 65;
	
	struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
 
 
    struct node* pre = NULL, *suc = NULL;
 
    inorderSucPre(root, pre, suc, key);
    if (pre != NULL)
      cout << "Predecessor is " << pre->data << endl;
    else
      cout << "No Predecessor";
 
    if (suc != NULL)
      cout << "Successor is " << suc->data;
    else
      cout << "No Successor";
	return 0;
}
