/*
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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode* temp = head;
        while (temp) {
            for (int i = 1; i < m; ++i) {
                if (!temp->next) return head;
                temp = temp->next;
            }
            auto* lastNode = temp;
            temp = temp->next;
            for (int i = 0; i < n; ++i) {
                if (!temp) {
                    lastNode->next = nullptr;
                    return head;
                }
                auto* nodeToDelete = temp;
                temp = temp->next;
                delete nodeToDelete;
                nodeToDelete = nullptr;
            }
            lastNode->next = temp;
        }
        return head;
    }
};