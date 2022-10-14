// C program for inorder tree traversal
#include <stdio.h>
#include <stdlib.h>

// A binary tree node has data, pointer to left child and a pointer to right child 
struct node {
	int data;
	struct node* left;
	struct node* right;
};

// Helper function that allocates a new node with the given data and NULL left and right pointers
struct node* newNode(int data)
{
	struct node* node
		= (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

// Given a binary tree, print its nodes in inorder
void printInorder(struct node* node)
{
	if (node == NULL)
		return;

	// first recur on left child 
	printInorder(node->left);

	// then print the data of node 
	printf("%d ", node->data);

	// now recur on right child 
	printInorder(node->right);
}


// Driver code
int main()
{
	struct node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	// Function call
	printf("\nInorder traversal of binary tree is \n");
	printInorder(root);

	getchar();
	return 0;
}
