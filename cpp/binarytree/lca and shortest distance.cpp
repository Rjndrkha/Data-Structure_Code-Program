#include <bits/stdc++.h>
using namespace std;

struct Node {

    struct Node* left ;
    struct Node* right ;
    int data ;

    Node ( int val )
    {
        data = val ;
        left = right = NULL ;
    }

};

int distance ( Node* root , int a  , int d )
{
    if ( root == NULL )
    return -1 ;

    if ( root -> data == a )
    return d ;

    return max ( distance ( root -> left , a , d+1 ) , distance ( root -> right , a , d+1 ) );
}

Node* lca ( Node* root , int a , int b )
{
    if ( root == NULL )
    return NULL ;

    if ( root -> data == a || root -> data == b )
    {
        return root ;
    }

    Node* leftLca = lca ( root -> left , a , b );
    Node* rightLca = lca ( root -> right , a , b );

    if ( leftLca && rightLca )
    return root ;

    if ( leftLca != NULL )
    return leftLca ;

    return rightLca ;
}

int shortest ( Node* root , int a , int b )
{
    Node* node = lca ( root , a , b ) ;
    int dis1 = distance( node , a , 0 )  ;
    int dis2 = distance( node , b , 0 )  ;
    return dis1 + dis2 ;
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
	root -> right -> right -> right = new Node ( 8 ) ;
	root -> right -> right -> right -> right = new Node ( 9 ) ;

	Node* node = lca ( root , 4 , 5 );
	cout << shortest ( root , 4 , 5 );
	cout << node -> data ;

	return 0;
}
