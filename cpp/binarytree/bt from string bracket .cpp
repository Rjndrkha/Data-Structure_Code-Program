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

void inorder ( Node* root )
{
    if ( root == NULL )
    return ;

    inorder ( root -> left  );
    cout << root -> data  << " " ;
    inorder ( root -> right );
}

Node* getbt ( string str , int& a )
{
    if ( a >= str.size() )
    return NULL ;

    Node* root = NULL ;
    if ( str[a] != '(' || str[a] != ')' )
    {
        int d = (int) str[a];
        root = new Node ( d-48 );
        a++ ;
    }

    if ( str[a] == '(' )
    {
        a++ ;
        root -> left = getbt ( str , a );
        a++ ;
    }

    if ( str[a] == ')' )
    {
        return root ;
    }

    if ( str[a] == '(' )
    {
        a++ ;
        root -> right = getbt ( str , a );
        a++ ;
    }

    if ( str[a] == ')' )
    {
        return root ;
    }

    return root ;
}


int main() {
	// your code goes here

    Node* root = new Node(8);
    root->left = new Node(6);
    root->right = new Node(10);
    root->left->left = new Node(5);
    root->left->right = new Node(7);
    root->right->left = new Node(9);
    root->right->right = new Node(11);

    int a = 0 ;
    Node* node = getbt( "1(2)(3)" , a );
    inorder ( node );

	return 0;
}
