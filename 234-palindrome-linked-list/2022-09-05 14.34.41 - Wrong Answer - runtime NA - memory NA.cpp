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
    bool isPalindrome(ListNode* head) {
        if (!head->next) return true;
        
        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head->next;
        ListNode* second = nullptr;
        
        while(fast && fast->next) {
            cout<<slow->val<<endl;
            second = slow->next;
            slow->next = prev;
            prev = slow;
            
            slow = second;
            
            fast = fast->next->next;
        }
        
        if (!fast) slow = slow->next;
        if (second) second = second->next;
        else second = head->next;
        while (slow) {
            if (slow->val != second->val) return false;
            slow = slow->next;
            second = second->next;
        }
        
        return true;
    }
};