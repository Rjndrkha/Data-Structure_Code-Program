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

Node * bToDLL(Node *rot)
    {
        // your code here

        stack<Node*> s ;
        Node* curr = rot ;
        int count = 0 ;
        Node* root = rot ;
        Node* root2 = rot ;

        while ( !s.empty() || curr != NULL )
        {
            if ( curr != NULL )
            {
                s.push( curr );
                curr = curr -> left ;
            }
            else
            {
                count ++ ;
                Node* node = s.top() ;
                s.pop();
                if ( count == 1 )
                {
                    root2 = node ;
                }
                else
                {
                    root -> right = node ;
                    node -> left = root ;
                }
                root = node ;
                curr = node -> right ;
            }
        }
        return root2 ;
    }

Node* linkedList ( Node* root )
{

    stack<Node*> s ;
    s.push ( root );

    Node* curr ;
    Node* val = s.top();

    while ( !s.empty() )
    {
        curr = s.top();
        s.pop();

        if ( curr -> right != NULL )
        s.push( curr -> right );

        if ( curr -> left != NULL )
        s.push( curr -> left );

        curr -> left = NULL ;
        if ( !s.empty() )
        {
            curr -> right = s.top() ;
        }
    }

    return val ;
}

void print ( Node* root )
{
    if ( root == NULL )
    return ;

        print( root ->left );
        cout << root -> data << " ";
        print ( root -> right );
}

void print_ ( Node* root )
{
    while ( root != NULL )
    {
        cout << root -> data << " ";
        root = root -> right ;
    }
}

void flatten ( Node* root )
{
    if ( root == NULL || ( root -> left == NULL && root -> right == NULL ) )
    return ;

    if ( root -> left != NULL )
    {
        flatten ( root -> left );

        Node* temp = root -> right ;
        root -> right = root -> left ;
        root -> left = NULL ;

        Node* t = root -> right ;
        while ( t != NULL )
        t = t -> right ;

        t = temp ;
    }

    flatten ( root -> right );

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
	root -> right -> right -> right = new Node ( 8 ) ;
	root -> right -> right -> right -> right = new Node ( 9 ) ;

	Node* node = linkedList( root );
	print ( node );

	return 0;
}
