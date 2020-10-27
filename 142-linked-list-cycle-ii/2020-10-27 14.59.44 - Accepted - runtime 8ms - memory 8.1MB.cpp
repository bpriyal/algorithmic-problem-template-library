/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode *slowPtr = head,*fastPtr =head;
        bool firstRun = true;
        while(slowPtr != fastPtr || firstRun) {
            firstRun = false;
            if (!slowPtr->next || !fastPtr->next || !fastPtr->next->next) {
                return nullptr;
            }
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        
        while(head != slowPtr) {
            head = head->next;
            slowPtr = slowPtr->next;
        }
        
        return head;
    }
};