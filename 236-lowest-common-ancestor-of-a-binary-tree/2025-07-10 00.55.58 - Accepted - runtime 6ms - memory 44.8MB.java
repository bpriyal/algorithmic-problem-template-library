/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    TreeNode anc;
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        helper (root, p, q);
        return anc;
    }

    boolean helper (TreeNode root, TreeNode p, TreeNode q) {
        if (anc == null) {
            if (root == null) return false;
            boolean l = helper (root.left, p, q);
            boolean r = helper (root.right, p , q);
            if (l == r && l == true) {
                anc = root;
                return false;
            }
            if (root == p || root == q) {
                if (l == true || r == true) {
                    anc = root;
                    return false;
                }
                return true;
            }
            return l || r;
        }
        return false;
    }
    
    
    
}