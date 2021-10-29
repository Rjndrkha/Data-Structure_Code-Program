/*
Given the root of a Complete Binary Tree consisting of N nodes, the task is to find the total number of nodes in the given Binary Tree.
*/

// Java program for the above approach
import java.util.*;

class GFG{

// Structure of a Tree Node
static class node {

	int data;
	node left;
	node right;
};


// Function to get the left height of
// the binary tree
static int left_height(node node)
{
	int ht = 0;
	while (node!=null) {
		ht++;
		node = node.left;
	}

	// Return the left height obtained
	return ht;
}

// Function to get the right height
// of the binary tree
static int right_height(node node)
{
	int ht = 0;
	while (node!=null) {
		ht++;
		node = node.right;
	}

	// Return the right height obtained
	return ht;
}

// Function to get the count of nodes
// in complete binary tree
static int TotalNodes(node root)
{

	// Base Case
	if (root == null)
		return 0;

	// Find the left height and the
	// right heights
	int lh = left_height(root);
	int rh = right_height(root);

	// If left and right heights are
	// equal return 2^height(1<<height) -1
	if (lh == rh)
		return (1 << lh) - 1;

	// Otherwise, recursive call
	return 1 + TotalNodes(root.left)
		+ TotalNodes(root.right);
}

// Helper function to allocate a new node
// with the given data
static node newNode(int data)
{
	node Node = new node();
	Node.data = data;
	Node.left = null;
	Node.right = null;
	return (Node);
}

// Driver Code
  public static void main(String[] args)
  {
      node root = newNode(1);
      root.left = newNode(2);
      root.right = newNode(3);
      root.left.left = newNode(4);
      root.left.right = newNode(5);
      root.right.left = newNode(9);
      root.right.right = newNode(8);
      root.left.left.left = newNode(6);
      root.left.left.right = newNode(7);

      System.out.print(TotalNodes(root));

  }
}

// This code is contributed by shikhasingrajput
