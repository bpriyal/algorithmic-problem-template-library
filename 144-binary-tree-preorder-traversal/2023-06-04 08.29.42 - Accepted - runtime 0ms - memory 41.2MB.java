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
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> pathToBeModified = new ArrayList();
        preorder(root, pathToBeModified);
        return pathToBeModified;
    }

    void preorder(TreeNode node, List<Integer> path){
        if(node != null){
            path.add(node.val);
            preorder(node.left, path);
            preorder(node.right, path);
        }
    }
}