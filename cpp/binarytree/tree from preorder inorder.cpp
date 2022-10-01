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

    node -> left = buildTree ( preorder , inorder , start , temp - 1 );
    node -> right = buildTree ( preorder , inorder , temp +1 , end );

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


int main() {
	// your code goes here

	int preorder[] = { 1 , 2 , 4 , 3 , 5 };
	int inorder[] = { 4 , 2 , 1 , 5 , 3 };

	inorder_ ( buildTree( preorder , inorder , 0 , 4 ) );

	return 0;
}
