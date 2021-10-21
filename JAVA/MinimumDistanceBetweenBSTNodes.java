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

class Solution 
{
    public void inorder(TreeNode root,List<Integer>set)
    {
       if(root==null)
       {
           return;
       }
        inorder(root.left,set);
        set.add(root.val);
        inorder(root.right,set);
    }
    int dif=Integer.MAX_VALUE;
    public int minDiffInBST(TreeNode root) 
    {
        List<Integer>set=new ArrayList<>();
        inorder(root,set);
        for(int i=0;i<set.size()-1;i++)
        {
            int temp=set.get(i+1)-set.get(i);
            if(dif>temp)
            {
                dif=temp;
            }
        }
        return dif;
    }
}
