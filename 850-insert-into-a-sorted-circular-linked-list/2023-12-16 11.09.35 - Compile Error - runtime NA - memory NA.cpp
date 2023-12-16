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
    unordered_set<Node*> _ptrAddresses;
    void _addNode(Node* current, int insertVal) {
        Node* newNode = new Node(insertVal, current->next);
        current->next = newNode;
    }
public:
    Node* insert(Node* head, int insertVal) {
        if (!head) {
            Node* newNode = new Node(insertVal);
            newNode->next = newNode;
            return newNode;
        }
        Node* temp = head;
        while (true) {
            _ptrAddresses.emplace(temp);
            if (insertVal == temp->val) {
                _addNode(temp. insertVal);
                break;
            }
            if (temp->val > temp->next->val) { // already at node with highest value
                if (insertVal >= temp->val || insertVal <= temp->next->val) {
                    _addNode(temp. insertVal);
                    break;
                }
            }
            if (insertVal > temp->val && insertVal < temp->next->val) {
                Node* newNode = new Node(insertVal, temp->next);
                temp->next = newNode;
                break;
            }
            if (_ptrAddresses.count(temp->next)) {
                _addNode(temp. insertVal);
                break;
            }
            temp = temp->next;
        }
        return head;
    }
};