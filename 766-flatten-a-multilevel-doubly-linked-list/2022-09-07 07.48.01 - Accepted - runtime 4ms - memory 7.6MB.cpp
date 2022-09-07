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
    Node* result = nullptr;
    Node* temp = nullptr;
    
    void util(Node* head) {
        if (!head) return;
        
        Node* newNode = new Node();
        newNode->val = head->val;
        newNode->prev = temp;
        newNode->child = nullptr;
        
        if (!temp) {
            result = temp = newNode;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
        
        util(head->child);
        util(head->next);
    }
public:
    Node* flatten(Node* head) {
        util(head);
        
        return result;
    }
};