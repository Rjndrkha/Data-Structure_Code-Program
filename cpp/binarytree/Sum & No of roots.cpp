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


int sumNodes(Node* node )
{
    if ( node == NULL )
    return 0 ;

    return ( sumNodes( node->left ) + sumNodes( node->right ) + node ->data );
}

int noNodes( Node* node )
{
    if ( node == NULL )
    return 0 ;

    return ( noNodes( node ->left ) + noNodes ( node ->right ) + 1 );
}

int main() {
	// your code goes here

	struct Node* root = new Node ( 1 ) ;
	root -> left = new Node ( 2 ) ;
	root -> right = new Node ( 3 ) ;
	root -> left ->left = new Node ( 4 ) ;
	root -> left -> right = new Node ( 5 ) ;
	root -> right -> left =  new Node ( 6 ) ;
	root -> right -> right = new Node ( 7 ) ;

	cout << sumNodes( root ) << " " << noNodes ( root );

	return 0;
}
