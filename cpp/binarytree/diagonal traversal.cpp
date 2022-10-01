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

vector<int> diagonal(Node *root)
{
   // your code here
   queue<Node*> q ;
   vector<int> vec ;

    Node* curr = root ;

    while ( !q.empty() || curr != NULL )
    {
        if ( curr != NULL )
        {
            q.push( curr );
            curr = curr -> right ;
        }
        else
        {
            curr = q.front();
            q.pop();
            vec.push_back( curr -> data );
            cout << curr -> data  << " ";
            curr = curr -> left ;
        }
    }

   return vec ;
}


int main() {
	// your code goes here

    struct Node* root = new Node ( 1 ) ;
	root -> left = new Node ( 2 ) ;
	root -> right = new Node ( 3 ) ;
	root -> left ->left = new Node ( 4 ) ;
	root -> left -> right = new Node ( 5 ) ;
	root -> left -> right -> right = new Node ( 8 ) ;
	root -> left -> right -> left  = new Node ( 9 ) ;
	root -> right -> left =  new Node ( 6 ) ;
	root -> right -> right = new Node ( 7 ) ;
	root -> right -> right -> left = new Node ( 10 );
    vector<int> vec = diagonal ( root );

	return 0;
}
