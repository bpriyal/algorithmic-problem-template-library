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
    void reorderList(ListNode* head) {
        vector<ListNode*> cache;
        ListNode* temp = head;
        while(temp) {
            cache.push_back(temp);
            temp = temp->next;
        }
        int size = cache.size();
        for (int i = 0; i < size / 2; i++) {
            cache[i]->next = cache[size - 1 - i];
            cache[size - 1 - i]->next = cache[i + 1];
            if (i + 1 == size / 2) {
                if (size%2 != 0) { 
                    cache[i + 1]->next = nullptr;
                }
                else {
                    cache[size - 1 - i] = nullptr;
                }
            }
        }
    }
};