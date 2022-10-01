void leafNodes( Node* root , vector<int>& v )
    {
        if ( root == NULL )
        return ;
        leafNodes(root->left , v);

        if(root->left==NULL&&root->right==NULL)
        v.push_back(root->data);

        leafNodes(root->right , v);

    }

    void leftNodes ( Node* root , vector<int>& v )
    {
        if ( root == NULL )
        return ;

        if ( root -> left == NULL )
        {
            if ( root -> right == NULL )
            return;

            v.push_back( root -> data );
            leftNodes ( root -> right , v );
        }
        else
        {
            v.push_back( root -> data );
            leftNodes ( root -> left , v );
        }

    }

    void rightNodes ( Node* root , vector<int>& v )
    {
        if ( root == NULL )
        return ;

        rightNodes ( root -> right , v );

        if ( root -> right == NULL )
        {
            if ( root -> left == NULL )
            return;

            rightNodes ( root -> left , v );
        }

        v.push_back( root -> data );
    }

    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> vec ;

        if ( root -> left == NULL && root -> right == NULL )
        {
            vec.push_back( root -> data );
            return vec ;
        }

        if ( root -> left == NULL )
            vec.push_back( root -> data );
        else
            leftNodes ( root , vec );

        leafNodes ( root , vec );

        if(root->right==NULL)
            vec.push_back(root->data);
        else
            rightNodes(root,vec);

        vec.pop_back() ;

        return vec ;
    }
