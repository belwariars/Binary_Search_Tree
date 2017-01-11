// Check if given tree is Binary Search Tree or NOT...

// OPTIMIZED SOLUTION: Time Complexity = O(N), Space Complexity = O(1)

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

int isBSTUtil(struct node* root, int min, int max)
{
	if(root == NULL)
		return 1;
	
	if(root->data > max || root->data < min)
		return 0;
		
	return isBSTUtil(root->left, min, root->data-1) && isBSTUtil(root->right, root->data+1, max);
}

int isBST(struct node* root)
{
	return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main()
{
  struct node *root = createnode(10);
  root->left        = createnode(2);
  root->right       = createnode(5);
 // root->left->left  = createnode(1);
  root->left->right = createnode(3); 
 
  if(isBST(root))
    printf("Is BST");
  else
    printf("Not a BST");
     
  getchar();
  return 0;
}  
