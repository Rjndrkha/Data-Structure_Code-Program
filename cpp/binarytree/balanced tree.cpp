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

bool balancedTree ( Node* root , int* h )
{
    if ( root == NULL )
    {
        *h = 0 ;
        return 1;
    }

    int lh = 0 , rh = 0 ;
    int a = balancedTree ( root -> left , &lh );
    int b = balancedTree ( root -> right , &rh );

    if ( !(a&&b) )
    {
        return 0 ;
    }

    *h = max ( lh , rh ) + 1 ;

    if ( abs( lh-rh ) > 1  )
    {
        return 0 ;
    }

    return 1 ;
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
	root -> right -> right -> right = new Node ( 8 ) ;
	root -> right -> right -> right -> right = new Node ( 9 ) ;


    int h = 0 ;

    bool bt = balancedTree ( root , &h );

    if ( bt == 0 )
    cout << "No" ;
    else
    cout << "Yes" ;

	return 0;
}
