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
struct Comp {
    int operator()(const Node* n1, const Node* n2) const {
        return n1->val < n2->val;
    }
};
class Solution {
public:
    Node* findRoot(vector<Node*> tree) {
        Node* temp = nullptr;
        for (auto* node : tree) {
            for (auto* childNode : node->children) childNode->val = -1 * childNode->val;
        }
        for (auto* node : tree) {
            if (node->val < 0) node->val = -1 * node->val;
            else temp = node;
        }
        return temp;
    }
};