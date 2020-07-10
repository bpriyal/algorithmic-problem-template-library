/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* root = head;
        stack<Node*> s;
        while(root) {
            if (!root->next && !root->child && s.empty()) {
                break;
            }
            if (!root->next && !root->child) {
                Node* temp = s.top();
                s.pop();
                root->next = temp;
                temp->prev = root;
            } else if (root->child) {
                if (root->next) {
                    s.push(root->next);
                }
                root->next = root->child;
                root->next->prev = root;
                root->child = nullptr;
            }
            root = root->next;
        }
        return head;
    }
};