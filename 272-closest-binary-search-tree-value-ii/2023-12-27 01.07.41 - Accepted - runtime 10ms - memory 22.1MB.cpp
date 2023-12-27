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
struct CustomComparator {
    bool operator()(pair<int, double> a, pair<int, double> b) const {
        return a.second < b.second;
    }
};
using PQ = priority_queue<pair<int, double>, vector<pair<int, double>>, CustomComparator>;
class Solution {
    void _closestKValues(TreeNode* root, double target, int k, PQ& pq) {
        if (!root) return;
        double diff = abs(root->val - target);
        if (pq.size() >= k) {
            if (diff < pq.top().second) {
                pq.pop();
                pq.emplace(root->val, diff);
            }
        } else {
            pq.emplace(root->val, diff);
        }
        _closestKValues(root->left, target, k, pq);
        _closestKValues(root->right, target, k, pq);
    }
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> result;
        priority_queue<pair<int, double>, vector<pair<int, double>>, CustomComparator> pq;
        _closestKValues(root, target, k, pq);
        while (!pq.empty()) {
            result.push_back(pq.top().first);
            pq.pop();
        }
        return result;
    }
};