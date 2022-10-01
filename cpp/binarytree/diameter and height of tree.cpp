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


int height ( Node* node )
{
    if ( node == NULL )
    return 0;

    return max ( height( node -> left ) , height( node -> right ) ) + 1 ;
}


int diameter(Node* root) {


    if ( root == NULL )
    return 0 ;

    int a = 1 ;
    a += height( root -> left );
    a += height( root -> right ) ;

    return max( max(diameter( root -> left ) , diameter ( root -> right )) , a ) ;
}

// optimised code for diameter O n
int diameter ( Node* root , int* h )
{
    if ( root == NULL )
    {
        *h = 0 ;
        return 0 ;
    }

    int lh = 0 , rh = 0 ;
    int ld = diameter ( root -> left , &lh );
    int rd = diameter ( root -> right , &rh );

    *h = max ( lh , rh ) + 1 ;
    int dia = lh + rh + 1 ;

    return ( max ( ld , max( rd , dia ) ) );
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

	int h = 0 ;

	cout << diameter( root , &h ) ;

	return 0;
}
