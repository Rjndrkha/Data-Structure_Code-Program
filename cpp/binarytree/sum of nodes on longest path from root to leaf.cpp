int height ( Node* root )
    {
        if ( root == NULL )
        return 0 ;

        return max ( height( root -> left ) , height ( root -> right ) ) + 1 ;
    }

    void sum ( Node* root , int d , vector<int>& vec , int h , int heigh )
    {
        if ( root != NULL )
        d += root -> data ;
        else
        return ;

        if ( root -> left == NULL && root -> right == NULL && h == heigh )
        {
            vec.push_back( d );
        }

        sum ( root->left , d  , vec , h+1 , heigh );
        sum ( root-> right , d , vec , h+1 , heigh );

    }


    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        vector<int> vec ;
        int h = height ( root );
        sum ( root , 0 , vec , 1 , h );

        sort ( vec.begin() , vec.end() );
        return vec[vec.size()-1] ;
    }
