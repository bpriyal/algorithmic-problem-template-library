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
    TreeNode retVal;
    public TreeNode searchBST(TreeNode root, int val) { 
        helper(root, val);
        return retVal;
    }
    void helper (TreeNode root, int val) {
        if (retVal == null) {
                    if (root == null) return;
        if (root.val == val) {
            retVal = root;
            return;
        }
        if (val < root.val) {
            helper(root.left, val);
        } else {
            helper(root.right, val);
        }
        }
    }
}