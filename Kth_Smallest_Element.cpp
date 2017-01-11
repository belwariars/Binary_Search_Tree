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

int n =0;

void kSmallest(struct node *root, int k)
{
	if(root!=NULL)
	{
		kSmallest(root->left, k);
		n++;
		if(n==k)
		{
			printf("%d", root->data);
			return;
		}
		kSmallest(root->right, k);
	}
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
 
    kSmallest(root, 3);
  return 0;
}  
