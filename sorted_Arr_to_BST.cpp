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

void preorder(struct node *root)
{
	if(root!= NULL)
	{
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

struct node *arrToBST(int arr[], int start, int end)
{
	if(start > end)
		return NULL;
		
	
	int mid = (start + end)/2 ;
	struct node *root = createnode(arr[mid]);	
	
	root->left = arrToBST(arr, start, mid-1);
	root->right = arrToBST(arr, mid+1, end);
	
	return root;
}

int main()
{
   	int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    
	struct node *root = arrToBST(arr, 0, n-1);
 	preorder(root);
 	
  return 0;
}  
