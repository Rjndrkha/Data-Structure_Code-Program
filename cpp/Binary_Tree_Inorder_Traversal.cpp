#include<bits/stdc++.h>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> output;
        TreeNode* curr=root;
        while(curr != NULL)
        {
            if(curr->left!=NULL)
            {
                TreeNode* temp=curr->left;
                while(temp->right!=NULL && temp->right != curr)
                {
                    temp=temp->right;
                }
                
                if(temp->right == curr)
                {
                    temp->right=NULL;
                    output.push_back(curr->val);
                    curr=curr->right;
                }
                else
                {
                    temp->right=curr;
                    curr=curr->left;
                }
            }
            else
            {
                output.push_back(curr->val);
                curr=curr->right;
            }
        }
        
        return output;
    }
};