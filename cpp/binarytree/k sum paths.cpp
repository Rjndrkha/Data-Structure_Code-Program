#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data ;
    Node* left ;
    Node* right ;
    Node( int val )
    {
        data = val ;
        left = right = NULL ;
    }
};

void kSumPaths ( Node* root , vector<int>& vec , int& k )
{
    if ( root == NULL )
    return ;

    vec.push_back( root -> data );

    kSumPaths ( root -> left , vec, k );
    kSumPaths ( root -> right , vec , k );

    int f = 0 ;

    for ( int i = vec.size() -1 ; i >= 0 ; i--  )
    {
        f += vec[i] ;
        if ( f == k )
        {
            for ( int j= i ; j < vec.size() ; j++ )
            {
                cout << vec[j] << " ";
            }
            cout << "\n";
        }
    }

    vec.pop_back();
}


int main() {
	// your code goes here

    Node* root = new Node(1);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->right = new Node(-1);
    root->right->left = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->right = new Node(2);

    int k = 5;
    vector<int> vec ;
    kSumPaths(root, vec , k);

	return 0;
}
