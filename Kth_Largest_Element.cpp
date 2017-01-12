//Find a Pair with given sum in BST...

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
	if(data > root->data)
	{
		root->right = insert(root->right, data);
	}
	
	return root;
}

void inorder(struct node *root)
{
	if(root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

void KthLargestElement(struct node* root, int* k, int* i)
{
	if(root != NULL)
	{
		KthLargestElement(root->right, k, i);
	(*i)++;
	if((*i) == (*k))
	{
		printf("\n%d Largest Element = %d", *k ,root->data);
		return;
	}
	KthLargestElement(root->left, k, i);
	}
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
    int i;
    for (int k=1; k<=7; k++)
    {
    	i=0;
    	KthLargestElement(root, &k, &i);
	}
	return 0;
}
