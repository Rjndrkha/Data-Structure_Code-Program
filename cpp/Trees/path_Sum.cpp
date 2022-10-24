struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 
class Solution {
    void rootToLeaf(TreeNode* root,int sum,vector<int> &temp,vector<vector<int>> &v){
        sum-=root->val;
        temp.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            if(!sum) v.push_back(temp);
            sum+=root->val;
            temp.pop_back();
            return;
        }
        if(root->left) rootToLeaf(root->left,sum,temp,v);
        if(root->right) rootToLeaf(root->right,sum,temp,v);
        sum+=root->val;
        temp.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> v;
        vector<int> temp;
        if(root==NULL) return v;
        rootToLeaf(root,targetSum,temp,v);
        return v;        
    }
};