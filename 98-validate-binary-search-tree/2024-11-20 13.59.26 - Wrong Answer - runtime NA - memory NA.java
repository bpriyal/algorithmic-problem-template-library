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
    public boolean isValidBST(TreeNode root) {
        //validated entire tree
        if (root == null) {
            return true;
        }

        if ((root.left != null && root.val <= root.left.val) || (root.right != null && root.val >= root.right.val)) {
            return false;
        }

        // if (root.left.val < root.val && root.right.val > root.val){
            return isValidBST(root.left) && isValidBST(root.right);
        // }
    }
}