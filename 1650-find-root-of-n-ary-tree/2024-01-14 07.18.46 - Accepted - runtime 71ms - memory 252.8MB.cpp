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
    int _salt = 500001;
public:
    Node* findRoot(vector<Node*> tree) {
        Node* temp = nullptr;
        for (auto* node : tree) {
            for (auto* childNode : node->children) childNode->val = _salt + childNode->val;
        }
        for (auto* node : tree) {
            if (node->val >= _salt) node->val = node->val - _salt;
            else temp = node;
        }
        return temp;
    }
};