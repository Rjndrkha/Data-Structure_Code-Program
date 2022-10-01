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

vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int> vec ;
    	vector<int> vec2 ;

    	int count = 1 ;

    	queue<Node*> q ;
    	q.push( root );
    	q.push( NULL );

    	while ( !q.empty() )
    	{
    	    Node* node = q.front();
    	    q.pop();

    	    if ( q.empty() )
    	    break ;

    	    if ( node == NULL )
    	    {
    	        q.push(NULL);
    	        count ++ ;
    	        continue ;
    	    }

    	    if ( node -> left != NULL )
    	    {
    	        q.push( node -> left );
    	    }

    	    if ( node -> right != NULL )
    	    {
    	        q.push( node -> right );
    	    }

    	    if ( count % 2 == 1 )
    	    {
    	        if ( vec2.size() > 0 )
    	        {
    	            reverse( vec2.begin() , vec2.end() );
    	            vec.insert( vec.end() , vec2.begin() , vec2.end() );
    	            vec2.clear();
    	        }

    	        vec.push_back( node -> data );
    	    }
    	    else
    	    {
    	        vec2.push_back( node -> data );
    	    }
    	}

    	if ( vec2.size() > 0 )
    	    {
    	       reverse( vec2.begin() , vec2.end() );
    	       vec.insert( vec.end() , vec2.begin() , vec2.end() );
    	       vec2.clear();
    	    }

    	return vec ;

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




	return 0;
}
