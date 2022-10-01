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

vector <int> bottomView(Node *root) {
        // Your Code Here
        int ls = 0 , rs = 0 ;


        queue<pair<Node* , int>> q ;
        stack<pair<Node* , int>> s ;
        pair<Node* , int> p , p2 ;
        p.first = root;
        p.second = 0 ;
        q.push(p);

        while( !q.empty() )
        {
            p = q.front();
            s.push(p);
            q.pop();

            if ( p.first -> left != NULL )
            {
                p2.first = p.first -> left ;
                p2.second = p.second - 1 ;
                q.push(p2);
            }

            if ( p.first -> right != NULL )
            {
                p2.first = p.first -> right ;
                p2.second = p.second + 1 ;
                q.push(p2);
            }
        }

        map<int , int> mp ;

        while ( !s.empty() )
        {
            p = s.top();
            s.pop();

            if ( mp.find(p.second) == mp.end() )
            mp[p.second] = p.first -> data ;
        }

        vector<int> vec ;

        for ( auto it : mp )
        {
            vec.push_back(it.second);
        }

        return vec ;
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
