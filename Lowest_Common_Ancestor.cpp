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

struct node* lowestCommonAncestor(struct node* root, int data1, int data2)
{
	if(root == NULL)
		return NULL;
		
	if(data1 < root->data && data2 < root->data)
	{
		return lowestCommonAncestor(root->left, data1, data2); // If you've to reach a particular node and return it you'll put return before recursion ...if you want to change something in tree and return the root... do root->left = recursion & root->right = recursion and in the end return root...
	}
	if(data1 > root->data && data2 > root->data)
	{
		return lowestCommonAncestor(root->right, data1, data2);
	}
	
	return root;
}

int main()
{
    struct node *root        = createnode(20);
    root->left               = createnode(8);
    root->right              = createnode(22);
    root->left->left         = createnode(4);
    root->left->right        = createnode(12);
    root->left->right->left  = createnode(10);
    root->left->right->right = createnode(14);
 
    int n1 = 10, n2 = 14;
    struct node *t = lowestCommonAncestor(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
 
    n1 = 14, n2 = 8;
    t = lowestCommonAncestor(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
 
    n1 = 10, n2 = 22;
    t = lowestCommonAncestor(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
  return 0;
}  
