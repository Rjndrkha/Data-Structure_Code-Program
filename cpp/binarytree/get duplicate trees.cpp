bool check ( Node* root1 , Node* root2 )
{
    if ( root1 == NULL && root2 == NULL )
        return 1 ;
    if ( root1 == NULL || root2 == NULL )
        return 0 ;

    if ( root1 -> data != root2 -> data )
        return 0 ;
    else
    {
        bool a = check ( root1-> left , root2 -> left );
        bool b = check ( root1-> right , root2 -> right );

        if ( a && b )
        {
            return 1 ;
        }
    }

    return 0 ;
}

bool checkEqual ( Node* root1 , Node* root2 , vector<Node*>& vec )
{
    if ( root1 == NULL && root2 == NULL )
        return 1 ;
    if ( root1 == NULL || root2 == NULL )
        return 0 ;

    if ( root1 -> data != root2 -> data )
        return 0 ;
    else
    {
        bool a = checkEqual ( root1-> left , root2 -> left , vec );
        bool b = checkEqual ( root1-> right , root2 -> right , vec );

        if ( a && b )
        {
            bool bt = 0 ;
            for ( int i=0 ; i < vec.size() ; i++ )
            {
               if ( check ( root1 , vec[i] ) )
               {
                   bt = 1 ;
               }
            }

            if ( bt == 0 )
            vec.push_back( root1 );

            return 1 ;
        }
    }

    return 0 ;
}

vector<Node*> printAllDups(Node* root)
{
    // Code here

    vector<Node*> vec ;

    if ( root == NULL )
         return vec ;

    unordered_map<int , vector<Node*>> mp ;
    queue<Node*> q ;
    q.push ( root );

    while ( !q.empty() )
    {
        Node* node = q.front();
        q.pop() ;

        if ( find(vec.begin(), vec.end(), node) == vec.end() )
        if ( mp.find( node -> data ) != mp.end() )
        {
            vector<Node*> node2 = mp[node -> data];
            for ( int i=0 ; i < node2.size() ; i++ )
            {
                bool bt = checkEqual ( node , node2[i] , vec );
            }
        }
        mp[node->data].push_back(node) ;


        if ( node -> left != NULL )
        {
             q.push( node -> left );
        }

        if ( node -> right != NULL )
        {
            q.push( node -> right );
        }
    }

    return vec ;
}
