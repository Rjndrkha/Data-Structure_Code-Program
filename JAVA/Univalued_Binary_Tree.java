/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {
    List<Integer> vals;
    public boolean isUnivalTree(TreeNode root) {
        vals = new ArrayList();
        dfs(root);
        for (int v: vals)
            if (v != vals.get(0))
                return false;
        return true;
    }

    public void dfs(TreeNode node) {
        if (node != null) {
            vals.add(node.val);
            dfs(node.left);
            dfs(node.right);
        }
    }
}
