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
        int size = 0;
        
        ListNode* current = head;
        ListNode *previous = nullptr;
        
        while(current) {
            ++size;
            current = current->next;
        }
        
        current = head;
        
        for(int i = 0; i < size/2; ++i) {
            ListNode* temp = current->next;
            current->next = previous;
            previous = current;
            current = temp;
        }
        
        if (size%2 != 0) current = current->next;
        
        while(previous && current) {
            if (previous->val != current->val) return false;
            previous = previous->next;
            current = current->next;
        }
        
        return true;
    }
};