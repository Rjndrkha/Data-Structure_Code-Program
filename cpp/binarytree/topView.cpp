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

vector<int> topView(Node *root)
    {
        //Your code here

        vector<int> vec ;
        vector<int> vec2 ;

        pair<Node* , int> p  , p2;

        queue<pair<Node* , int>> q ;
        p.first = root;
        p.second = 0;
        q.push(p);

        int l = 0 , r = 0 ;

        while ( !q.empty() )
        {
            p = q.front();
            q.pop();

            if ( p.second < l )
            {
                vec.push_back( p.first -> data );
                l = p.second ;
            }

            if ( p.second > r )
            {
                vec2.push_back( p.first -> data );
                r = p.second ;
            }

            if ( p.first ->left != NULL )
            {
                p2.first = p.first -> left ;
                p2.second = p.second -1 ;
                q.push( p2 );
            }

            if ( p.first ->right != NULL )
            {
                p2.first = p.first -> right ;
                p2.second = p.second + 1 ;
                q.push( p2 );
            }
        }

        reverse ( vec.begin() , vec.end() );
        vec.push_back( root -> data );
        vec.insert( vec.end() , vec2.begin() , vec2.end() );

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


    vector<int> vec = topView ( root );

    for ( int i=0 ; i < vec.size() ; i++ )
    {
        cout << vec[i] << " " ;
    }

	return 0;
}
