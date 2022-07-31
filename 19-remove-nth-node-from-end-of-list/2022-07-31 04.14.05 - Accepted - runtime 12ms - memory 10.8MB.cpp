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
        ListNode* trailSlow = nullptr;
        
        for(int i = 0; i < n; ++i) {
            fast = fast->next;
        }
        
        while(fast) {
            fast = fast->next;
            trailSlow = slow;
            slow = slow->next;
        }
        
        if(trailSlow == nullptr) head = head->next;
        else trailSlow->next = slow->next;
        
        delete slow;
        slow = nullptr;
        return head;
    }
};