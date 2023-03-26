/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int getHeight(TreeNode* root) {
        int height = 0;
        TreeNode* temp = root;
        while (temp) {
            ++height;
            temp = temp->left;
        }
        return height;
    }
    bool nodeExists(int low, int high, int idx, TreeNode* root, int height, int d) {
        if (!root) return false;
        if (d == height) return true;
        int mid = low + (high - low) / 2;
        if (idx > mid) return nodeExists(mid, high, idx, root->right, height, d + 1);
        else return nodeExists(low, mid, idx, root->left, height, d + 1);
    }
public:
    // int countNodes(TreeNode* root) {
    //     int height = getHeight(root);
    //     if (height == 0 || height == 1) return height;
    //     int low = 0;
    //     int high = pow(2, height - 1) - 1;
    //     int maxRange = high;
    //     while (low <= high) {
    //         int mid = low + (high - low) / 2;
    //         if (nodeExists(0, maxRange, mid, root, height, 1)) {
    //             low = mid + 1;
    //         } else {
    //             high = mid - 1;
    //         }
    //     }

    //     return pow(2, height - 1) - 1 + low;
    // }

    int getLeftHeight(TreeNode* root) {
        int height = 0;
        while (root) {
            ++height;
            root = root->left;
        }
        return height;
    }

    int getRightHeight(TreeNode* root) {
        int height = 0;
        while (root) {
            ++height;
            root = root->right;
        }
        return height;
    }

    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int leftHeight = getLeftHeight(root);
        int rightHeight = getRightHeight(root);

        if (leftHeight == rightHeight) return pow(2, leftHeight) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};