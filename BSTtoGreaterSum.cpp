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

void inorder(struct node *root)
{
	if(root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

void BSTtoGreaterSum(struct node *root, int *sum, int *sum2)
{
	if(root != NULL)
	{
		BSTtoGreaterSum(root->right, sum, sum2);
		*sum2 = *sum2 + root->data;
		root->data = *sum;
		*sum = *sum2;
		BSTtoGreaterSum(root->left, sum, sum2);
	}
}

int main()
{
	struct node *root = createnode(11);
    root->left = createnode(2);
    root->right = createnode(29);
    root->left->left = createnode(1);
    root->left->right = createnode(7);
    root->right->left = createnode(15);
    root->right->right = createnode(40);
    root->right->right->left = createnode(35);
    
    int sum1=0;
    int sum2 = 0;
    inorder(root);
    BSTtoGreaterSum(root, &sum1, &sum2);
    printf("\n\n");
    inorder(root);
	return 0;
}
