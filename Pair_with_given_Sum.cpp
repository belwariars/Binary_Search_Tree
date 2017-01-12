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

unordered_set<int> container;

void pairWithSum(struct node* root, int sum)
{
	if(root != NULL)
	{
		pairWithSum(root->left, sum);
		if(container.find(root->data)!=container.end())
		{
			printf("The pair is = %d and %d", root->data, sum-(root->data));
			return;
		}
		else
		{
			container.insert(sum - (root->data));
		}
		pairWithSum(root->right, sum);
	}
}

int main()
{
	struct node *root =  createnode(15);
    root->left = createnode(10);
    root->right = createnode(20);
    root->left->left = createnode(8);
    root->left->right = createnode(12);
    root->right->left = createnode(16);
    root->right->right = createnode(25);
    
    pairWithSum(root, 33);
	return 0;
}
