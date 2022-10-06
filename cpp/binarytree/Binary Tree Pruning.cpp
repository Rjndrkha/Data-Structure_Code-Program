//You have been given a Binary Tree where the value of each node is either 0 or 1. 
//Your task is to return the same Binary Tree but all of its subtrees that don't contain a 1 have been removed.
//Note : A subtree of a node X is X, plus every node that is a descendant of X.


#include <bits/stdc++.h>
using namespace std;

struct Node {
  int key;
  Node* left;
  Node* right;
};

// Function to create a node with 'value' as the data
// stored in it.
// Both the children of this new Node are initially null.
 Node* newNode(int value)
{
  Node* n = new Node;
  n->key = value;
  n->left = NULL;
  n->right = NULL;
  return n;
}



// PostOrder traversal 
bool hasOne(Node* root)
{
    // If root is null, there is no 1
    if(root == NULL)
    {
        return false;
    }

    // Find if left and right subtrees contain a 1 or not
    bool oneInLeftSubtree = hasOne(root -> left);
    bool oneInRightSubtree = hasOne(root -> right);

    // If there's no 1 in left subtree
    if(oneInLeftSubtree == false) 
    {
        // Delete left subtree
        root -> left = NULL;
    }

    // If there's no 1 in right subtree
    if(oneInRightSubtree == false) 
    {
        // Delete right subtree
        root -> right = NULL;
    } 

    // If there is any 1 in the subtree, return true 
    if(root -> key == 1 || oneInLeftSubtree || oneInRightSubtree)
    {
        return true;
    }

    // Else return false
    return false;
}

Node* binaryTreePruning(Node* root)
{
    // If there is a 1 in the whole tree
    if(hasOne(root) == true)
    {
        return root;
    }

    // Else, delete the whole tree
    return NULL;
}

 Node* insertValue(struct Node* root, int value,queue<Node *>& q)
{
  Node* node = newNode(value);
  if (root == NULL)
    root = node;

  // The left child of the current Node is
  // used if it is available.
  else if (q.front()->left == NULL)
    q.front()->left = node;

  // The right child of the current Node is used
  // if it is available. Since the left child of this
  // node has already been used, the Node is popped
  // from the queue after using its right child.
  else {
    q.front()->right = node;
    q.pop();
  }

  // Whenever a new Node is added to the tree, its
  // address is pushed into the queue.
  // So that its children Nodes can be used later.
  q.push(node);
  return root;
}

// This function mainly calls insertValue() for
// all array elements. All calls use same queue.
Node* createTree(int arr[], int n)
{
  Node* root = NULL;
  queue<Node*> q;
  for (int i = 0; i < n; i++)
  root = insertValue(root, arr[i], q);
  return root;
}

// This is used to verify the logic.
void levelOrder(Node* root)
{
  if (root == NULL)
    return;
  queue<Node*> n;
  n.push(root);
  while (!n.empty()) {
    cout << n.front()->key << " ";
    if (n.front()->left != NULL)
      n.push(n.front()->left);
    if (n.front()->right != NULL)
      n.push(n.front()->right);
    n.pop();
  }
}

// Testing the code
int main()
{
  cout << "Enter the number of nodes\n";
  int n;
  cin >> n;
  int arr[n];
  cout << "enter the levelOrder traversal of the tree\n";
  for(int i=0;i<n;i++){
    cin>> arr[i];
  }
  Node* root = createTree(arr, n);
  Node* answer_root = binaryTreePruning(root);
  cout << "Tree after pruning operation is :\n";
  levelOrder(answer_root);
  return 0;
}


/*
    Time Complexity - O(N)
    Space Complexity - O(N)

    where N is the number of nodes in the binary tree.
*/