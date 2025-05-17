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

    int MAX = 0;

    public int diameterOfBinaryTree(TreeNode root) {
        setMaxDiaOrGiveMaxPath(root);
        return MAX;
    }

    int setMaxDiaOrGiveMaxPath (TreeNode root) {
        if (root == null) return 0;
    
        int leftLen = setMaxDiaOrGiveMaxPath(root.left);
        int rightLen = setMaxDiaOrGiveMaxPath(root.right);

        MAX = Math.max(MAX, leftLen + rightLen);

        return Math.max(leftLen + 1, rightLen + 1);
    }


}