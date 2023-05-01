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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        unordered_map<int, int> cache;
        ListNode* tempIterator = head;

        while (tempIterator) {
            ++cache[tempIterator->val];
            tempIterator = tempIterator->next;
        }

        // fix head first
        while (head && cache[head->val] > 1) {
            ListNode* temp = head;
            head = head->next;
        }
        if (!head) return nullptr;

        tempIterator = head->next;
        ListNode* prev = head;
        while (tempIterator) {
            if (cache[tempIterator->val] > 1) {
                prev->next = tempIterator->next;
                ListNode* tempToDelete = tempIterator;
                tempIterator = tempIterator->next;
                delete tempToDelete;
                tempToDelete = nullptr;
            } else {
                prev = tempIterator;
                tempIterator = tempIterator->next;
            }

        }
        return head;
    }
};