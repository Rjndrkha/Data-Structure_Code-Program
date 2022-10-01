 void bottomNodes ( TreeNode* root , int k , vector<int>& vec )
    {
        if ( root == NULL )
            return ;

        queue<TreeNode*> q;
        q.push( root );
        q.push( NULL );

        while ( !q.empty() )
        {
            TreeNode* node = q.front();
            q.pop();

            if ( q.empty() )
                break ;

            if ( node == NULL )
            {
                k-- ;
                q.push( NULL );
                continue ;
            }

            if ( k == 0 )
            {
                vec.push_back( node -> val );
            }

            if ( node -> left != NULL )
            {
                q.push( node -> left );
            }

            if ( node -> right != NULL )
            {
                q.push( node -> right );
            }
        }
    }


    int upperNodes ( TreeNode* root , TreeNode* target , int k , vector<int>& vec )
    {
        if ( root == NULL )
            return -1 ;

        if ( root -> val == target -> val )
        {
            bottomNodes ( target , k , vec );
            return 0 ;
        }

        int ls = upperNodes ( root ->left , target , k , vec );
        if ( ls != -1 )
        {
            if ( ls + 1 == k )
                vec.push_back( root->val );
            else
            {
                bottomNodes ( root -> right , k-ls-2 , vec );
            }

            return ls + 1 ;
        }

        int rs = upperNodes ( root ->right , target , k , vec );
        if ( rs != -1 )
        {
            if ( rs + 1 == k )
                vec.push_back( root->val );
            else
            {
                bottomNodes ( root -> left , k-rs-2 , vec );
            }

            return rs + 1 ;
        }
        return -1 ;
    }


    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        vector<int> vec ;
        upperNodes ( root , target , k , vec );
        return vec ;
    }
