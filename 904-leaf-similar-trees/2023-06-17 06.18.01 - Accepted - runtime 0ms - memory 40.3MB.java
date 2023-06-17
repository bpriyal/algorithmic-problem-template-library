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
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {

        TreeNode node = root1;
        List<Integer> leaves1 = new ArrayList<>();
        List<Integer> leaves2 = new ArrayList<>();
        leaves(root1,leaves1);
        leaves(root2,leaves2);
        return leaves1.equals(leaves2);
    }

    void leaves(TreeNode node, List<Integer> listToModify){
        if(node != null){
            if(node.left == null && node.right == null){
                listToModify.add(node.val);
            }
            leaves(node.left,listToModify);
            leaves(node.right,listToModify);
        }
    }

}