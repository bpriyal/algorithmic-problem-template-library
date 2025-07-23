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
    List<Integer> levels = new ArrayList();
    int LEVEL = 0;
    public List<Integer> rightSideView(TreeNode root) {
        trav (root, LEVEL);
        return levels;
    }

    void trav (TreeNode node, int level) {
        if (node == null) return;
        if (level == LEVEL) {
            levels.add(node.val);
            LEVEL++;
        }
        trav (node.right, level + 1);
        trav (node.left, level + 1);
    }
}