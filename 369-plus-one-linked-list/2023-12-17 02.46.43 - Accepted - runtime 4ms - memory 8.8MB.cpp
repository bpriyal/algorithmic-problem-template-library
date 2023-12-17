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
    ListNode* _reverseList(ListNode* head) {
        if (!head) return nullptr;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    void _plusOne(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = nullptr;
        int carry = 1;
        while (temp) {
            if (temp->val < 9) {
                temp->val += carry;
                carry = 0;
                break;
            }
            temp->val = 0;
            carry = 1;
            prev = temp;
            temp = temp->next;
        }
        if (carry) {
            prev->next = new ListNode(1, nullptr);
        }
    }
public:
    ListNode* plusOne(ListNode* head) {
        ListNode *reversedHead = _reverseList(head);
        _plusOne(reversedHead);
        return _reverseList(reversedHead);
    }
};