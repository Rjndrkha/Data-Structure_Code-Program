/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        heightOfTree(root, diameter);
        return diameter;
    }
    
    int heightOfTree(TreeNode* node, int& d){
        if(node == NULL) return 0;
        
        int lh = heightOfTree(node -> left, d);
        int rh = heightOfTree(node -> right, d);
        
        d = max(d, rh+lh);
        
        return (max(lh,rh) +1);
    }
};