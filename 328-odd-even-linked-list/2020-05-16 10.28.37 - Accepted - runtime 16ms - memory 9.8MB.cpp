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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *evenHead = even;
        while (true) {
            if (!even || !odd || !(even->next)) {
                odd->next = evenHead;
                break;
            }
            odd->next = even->next;
            odd = even->next;
            
            if (!(odd->next)) {
                even->next = NULL;
                odd->next = evenHead;
                break;
            }
            even->next = odd->next;
            even = odd->next;
        }
        return head;
    }
};