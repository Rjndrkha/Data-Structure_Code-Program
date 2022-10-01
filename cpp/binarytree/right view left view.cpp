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

vector<int> rightView ( Node* node )
{
    vector<int> vec ;
    queue<Node*> q ;
    q.push( node );
    q.push( NULL );

    while ( !q.empty() )
    {
        Node* root = q.front();
        q.pop() ;

        if ( q.empty() )
        break ;

        if ( root == NULL )
        {
            q.push( NULL );
            continue ;
        }

        if ( q.front() == NULL )
        vec.push_back(root -> data);

        if ( root -> left != NULL )
        {
            q.push( root -> left );
        }

        if ( root -> right != NULL )
        {
            q.push( root -> right );
        }
    }

    return vec ;

}

vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> vec ;
   queue<Node*> q ;


   if ( root != NULL )
   {
        q.push( root );
        q.push( NULL );
        vec.push_back(root -> data);
   }


   while( !q.empty() )
   {
       Node* node = q.front() ;
       q.pop();

       if ( q.empty() )
       break ;

       if ( node == NULL )
       {
           Node* n = q.front();
           vec.push_back( n-> data );
           q.push(NULL);
           continue ;
       }

       if ( node -> left != NULL )
       {
           q.push(node->left);
       }

       if ( node -> right != NULL )
       {
           q.push(node -> right);
       }

   }

   return vec ;

}

void inorderPrint ( Node* root )
{
    if ( root == NULL )
    return ;

    inorderPrint (root -> left) ;
    cout << root -> data << " " ;
    inorderPrint ( root -> right ) ;
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
// 	root -> right -> right -> right = new Node ( 8 ) ;
// 	root -> right -> right -> right -> right = new Node ( 9 ) ;


    vector<int> vec = rightView ( root );

    for ( int i=0 ; i < vec.size() ; i++ )
    {
        cout << vec[i] << " " ;
    }

	return 0;
}
