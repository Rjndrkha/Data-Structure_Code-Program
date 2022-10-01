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


int search ( int inorder[] , int start , int end , int curr )
{
    for ( int i= start ; i <=end ; i++ )
    {
        if ( inorder[i] == curr )
        {
            return i ;
        }
    }
    return -1 ;
}

int indx = 0 ;

Node* buildTree ( int preorder[] , int inorder[] , int start , int end )
{

    if ( start > end )
    {
        return NULL ;
    }

    int curr = preorder[indx] ;
    indx ++ ;

    Node* node = new Node ( curr );

    if ( start == end )
    {
        return node ;
    }

    int temp = search ( inorder , start , end , curr );

    node -> right = buildTree ( preorder , inorder , start , temp-1 );
    node -> left = buildTree ( preorder , inorder , temp+1 , end );

    return node ;

}

void inorder_ ( Node* root )
{
    if ( root == NULL )
    return ;

    inorder_ (root -> left) ;
    cout << root -> data << " " ;
    inorder_ ( root -> right ) ;
}


Node* mirrorTree ( Node* root )
{
    if ( root == NULL )
    return root ;

    Node* node = root-> left ;
    root -> left = root -> right ;
    root -> right = node ;

    mirrorTree ( root -> left ) ;
    mirrorTree ( root -> right );

    return root ;
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

	inorder_ ( root );
	cout << "\n" ;
	inorder_ ( mirrorTree( root ) );

	return 0;
}
