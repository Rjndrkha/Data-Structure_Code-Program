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

void postorder ( Node* root )
{
    stack<Node*> s ;
    stack<int> s2 ;
    Node* curr = root ;
    s.push( root );

    while ( !s.empty() )
    {
        curr = s.top();
        s.pop();

        s2.push( curr -> data );

        if ( curr-> left != NULL )
        s.push( curr -> left );

        if ( curr -> right != NULL )
        s.push( curr -> right );
    }

    while ( !s2.empty() )
    {
        cout << s2.top() << " ";
        s2.pop();
    }

}

void preorder ( Node* root )
{
    stack<Node*> s ;
    Node* curr = root ;

    while ( !s.empty() || curr != NULL )
    {
        if ( curr != NULL )
        {
            cout << curr -> data << " " ;
            s.push( curr );
            curr = curr -> left ;
        }
        else
        {
            curr = s.top();
            s.pop();
            curr = curr -> right ;
        }
    }
}

void inorder ( Node* root )
{
    Node* curr = root ;
    stack<Node*> s;

    while ( !s.empty() || curr != NULL )
    {
        if ( curr != NULL )
        {
            s.push( curr );
            curr = curr -> left ;
        }
        else
        {
            curr = s.top();
            s.pop();
            cout << curr -> data << " " ;
            curr = curr -> right ;
        }
    }
}

int main() {
	// your code goes here

// 	int preorder[] = { 1 , 2 , 4 , 3 , 5 };
// 	int inorder[] = { 4 , 2 , 1 , 5 , 3 };

	struct Node* root = new Node ( 1 ) ;
	root -> left = new Node ( 2 ) ;
	root -> right = new Node ( 3 ) ;
	root -> left ->left = new Node ( 4 ) ;
	root -> left -> right = new Node ( 5 ) ;
	root -> right -> left =  new Node ( 6 ) ;
	root -> right -> right = new Node ( 7 ) ;
	root -> right -> right -> right = new Node ( 8 ) ;
	root -> right -> right -> right -> right = new Node ( 9 ) ;


    inorder ( root );
    preorder ( root );
    postorder ( root );

	return 0;
}
