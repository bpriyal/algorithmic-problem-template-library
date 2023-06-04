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
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> pathToBeModified = new ArrayList();
        inorder(root,pathToBeModified);
        return pathToBeModified;
    }

    void inorder(TreeNode node, List<Integer> path){
        if(node != null){
            inorder(node.left, path);
            path.add(node.val);
            inorder(node.right, path);
        }
    }
}