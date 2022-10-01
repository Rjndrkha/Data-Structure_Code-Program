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

bool sum ( Node* root , int* h )
    {
        if ( root == NULL )
        {
            *h = 0 ;
            return 1 ;
        }

        int ls = 0 , rs = 0 ;

        bool a = sum ( root -> left , &ls );
        bool b = sum ( root -> right , &rs );

        *h = ls + rs + root -> data ;

        if ( !(a&&b) )
        return 0 ;

        if ( ls != 0 || rs != 0 )
        if ( (ls + rs) != root -> data )
        {
            return 0 ;
        }

        return 1 ;
    }

    bool check(Node *root)
    {
        //Your code here

        int order = 0 ;

        unordered_set<int> s ;
        queue<Node*> q ;
        q.push(root);
        q.push(NULL);

        while ( !q.empty() )
        {
            Node* node = q.front();
            q.pop();

            if ( q.empty() )
            break ;

            if ( node == NULL )
            {
                q.push( NULL );
                order ++ ;
                continue ;
            }

            if ( node -> left == NULL && node -> right == NULL )
            s.insert( order );

            if ( node -> left != NULL )
            {
                q.push( node -> left );
            }

            if ( node -> right != NULL )
            {
                q.push( node -> right );
            }
        }

        if ( s.size() == 1 )
        return 1 ;
        else
        return 0 ;

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
