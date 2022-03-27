/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        
        if (head == nullptr) return head;
        
        ListNode* temp = head;
        while (temp) {
            temp = temp->next;
            ++size;
        }
        
        if (size == n) {
            ListNode* r = head->next;
            head->next = nullptr;
            delete(head);
            return r;
        }
        
        temp = head;
        for(int i = 0;i < size-n-1;++i) {
            temp = temp->next;
        }
        
        ListNode* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        nodeToDelete->next = nullptr;
        delete(nodeToDelete);
        
        return head;
    }
};