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

    inorder ( root -> left );
    cout << root -> data << " ";
    inorder ( root -> right );

}

void getCount ( Node* root , int& a , vector<int>& vec , unordered_set<int>& s )
{
    if ( root == NULL )
    return ;

    getCount ( root -> left , a , vec , s );
    if ( root -> data != vec[a] )
    {
        s.insert( vec[a] );
        s.insert( root -> data );
        root -> data = vec[a];
    }
    getCount ( root -> right , a , vec , s );
}

void inorder ( Node* root , vector<int>& vec )
{
    if ( root == NULL )
    return ;

    inorder ( root -> left , vec );
    vec.push_back( root -> data );
    inorder ( root -> right , vec );
}

int bst ( Node* root )
{
    vector<int> vec ;
    inorder ( root , vec );

    sort ( vec.begin() , vec.end() );

    unordered_set<int> s ;
    int a = 0 ;
    getCount ( root , a , vec , s );

    return s.size()/2 ;
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

    cout << bst ( root  );
    // answer 3

	return 0;
}
