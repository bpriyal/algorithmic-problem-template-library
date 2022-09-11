/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node* temp = head;
        Node* copy = nullptr;
        Node* result = nullptr;
        
        // copy list
        while (temp) {
            Node* currentNext = temp->next;
            temp->next = new Node(temp->val);
            temp->next->next = currentNext;
            
            temp = temp->next->next;
        }
        
        // assign random ptrs
        temp = head;
        while (temp) {
            temp->next->random = temp->random? temp->random->next : nullptr;
            temp = temp->next->next;
        }
        
        // restore the list
        
        temp = head;
        result = head->next;
        while (temp) {
            Node* currentNext = temp->next;
            temp->next = currentNext->next;
            
            if (temp->next) {
                currentNext->next = temp->next->next;
            } else {
                currentNext->next = nullptr;
            }
            
            temp = temp->next;
        }
        
        return result;
    }
};