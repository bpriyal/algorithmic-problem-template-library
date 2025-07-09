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
    List<Integer> L;
    // List<integer> L2 = new ArrayList();
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        L = new ArrayList();
        helper(root1);
        List<Integer> l1 = L;
        L = new ArrayList();
        helper(root2);
        List<Integer> l2 = L;
        return l1.equals(l2);
    }

    void helper (TreeNode root) {
        if (root == null) return;
        if (root.left == null && root.right == null) {
            L.add(root.val);
        }
        helper(root.left);
        helper(root.right);
    }
}