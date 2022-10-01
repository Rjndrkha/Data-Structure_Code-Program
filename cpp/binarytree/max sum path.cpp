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

int greatestPath ( Node* root , int& ans )
{
    if ( root == NULL )
    return 0 ;

    int val = root -> data ;
    int left = greatestPath ( root -> left , ans );
    int right = greatestPath ( root -> right , ans );

    int v = max ( max ( val , val + left + right ) , max ( val +  left , val + right ) );
    ans = max( v , ans );

    return max ( val , max ( val + left , val + right ) );

}


int main() {
	// your code goes here

    Node* root = new Node ( 1 );
    root -> left = new Node ( 2 );
    root -> right = new Node ( 3 );
    root -> left -> left = new Node ( 4 );
    root -> left -> right = new Node ( 5 );

    int ans = INT_MIN ;
    greatestPath ( root , ans );
    cout << ans ;

	return 0;
}
