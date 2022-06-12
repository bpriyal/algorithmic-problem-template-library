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
        ListNode* slow = head;
        ListNode* fast = head;
        
        for(int i = n; i > 0;--i) {
            fast = fast->next;
        }
        
        if (!fast) {
            ListNode *temp = slow->next;
            delete(slow);
            slow = nullptr;
            
            return temp;
        }
        
        while(fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode* toDelete = slow->next;
        slow->next = toDelete->next;
        
        delete(toDelete);
        toDelete = nullptr;
        
        return head;
    }
};