/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    int _result = 0;
    int _diameter(Node* root) {
        if (!root) return 0;
        int nChildren = root->children.size();
        if (nChildren == 0) return 1;
        vector<int> subHeights(nChildren);
        for (int i = 0; i < nChildren; ++i) {
            subHeights[i] = _diameter(root->children[i]);
        }
        sort(subHeights.begin(), subHeights.end());
        int maxDistance = nChildren < 2? subHeights.back() : subHeights[nChildren - 1] + subHeights[nChildren - 2];
        _result = max(_result, maxDistance);
        return subHeights[nChildren - 1] + 1;
    }
public:
    int diameter(Node* root) {
        _diameter(root);
        return _result;
    }
};