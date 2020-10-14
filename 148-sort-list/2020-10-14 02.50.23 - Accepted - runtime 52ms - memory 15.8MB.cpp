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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* secondHead = slow->next;
        slow->next = nullptr;
        head = sortList(head);
        secondHead = sortList(secondHead);
        
        ListNode dummy = ListNode(0);
        ListNode* prev = &dummy;
        while (head != nullptr && secondHead != nullptr)
        {
            if (head->val < secondHead->val)
            {
                prev->next = head;
                head = head->next;
            }
            else
            {
                prev->next = secondHead;
                secondHead = secondHead->next;
            }
            prev = prev->next;
        }
        prev->next = head != nullptr ? head : secondHead;
        return dummy.next;
    }
};