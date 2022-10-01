#include <bits/stdc++.h>
using namespace std;


struct Node {

    int data ;
    struct Node* left ;
    struct Node* right ;

    Node ( int val )
    {
        data = val ;
        left = NULL ;
        right = NULL ;
    }
};

int sum ( Node* root )
{
    if ( root == NULL )
    return 0 ;

    return sum(root -> left) + sum(root -> right) + root->data ;
}

void sum ( Node* root , int* h )
{
    if ( root == NULL )
    {
        *h = 0 ;
        return ;
    }

    int ls = 0 , rs = 0 ;

    sum ( root->left , &ls );
    sum ( root->right , &rs );

    *h = ls + rs + root ->data ;
    root -> data = *h ;
}

void inorderPrint ( Node* root )
{
    if ( root == NULL )
    return ;

    inorderPrint (root -> left) ;
    cout << root -> data << " " ;
    inorderPrint ( root -> right ) ;
}

int main() {
	// your code goes here

	int preorder[] = { 1 , 2 , 4 , 3 , 5 };
	int inorder[] = { 4 , 2 , 1 , 5 , 3 };

	struct Node* root = new Node ( 1 ) ;
	root -> left = new Node ( 2 ) ;
	root -> right = new Node ( 3 ) ;
	root -> left ->left = new Node ( 4 ) ;
	root -> left -> right = new Node ( 5 ) ;
	root -> right -> left =  new Node ( 6 ) ;
	root -> right -> right = new Node ( 7 ) ;

    inorderPrint ( root );
    int h = 0 ;
	sum( root , &h ) ;
    cout << "\n";
    inorderPrint ( root );
	return 0;
}
