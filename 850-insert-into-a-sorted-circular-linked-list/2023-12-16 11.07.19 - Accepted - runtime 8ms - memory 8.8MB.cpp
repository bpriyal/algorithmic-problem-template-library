/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
    unordered_set<Node*> ptrAddresses;
public:
    Node* insert(Node* head, int insertVal) {
        if (!head) {
            Node* newNode = new Node(insertVal);
            newNode->next = newNode;
            return newNode;
        }
        Node* temp = head;
        // if (head == head->next) { // single node circular list
        //     Node* newNode = new Node(insertVal, temp->next);
        //     temp->next = newNode;
        //     return head;
        // }
        while (true) {
            ptrAddresses.emplace(temp);
            cout<<temp->val<<endl;
            if (insertVal == temp->val) {
                Node* newNode = new Node(insertVal, temp->next);
                temp->next = newNode;
                break;
            }
            if (temp->val > temp->next->val) { // already at node with highest value
                if (insertVal >= temp->val || insertVal <= temp->next->val) {
                    Node* newNode = new Node(insertVal, temp->next);
                    temp->next = newNode;
                    break;
                }
            }
            if (insertVal > temp->val && insertVal < temp->next->val) {
                Node* newNode = new Node(insertVal, temp->next);
                temp->next = newNode;
                break;
            }
            if (ptrAddresses.count(temp->next)) {
                Node* newNode = new Node(insertVal, temp->next);
                temp->next = newNode;
                break;
            }
            temp = temp->next;
        }
        return head;
    }
};