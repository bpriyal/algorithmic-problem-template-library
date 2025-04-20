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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      int size = lists.size();
      auto comp = [](ListNode* l1, ListNode* l2) -> bool {
        return l1->val > l2->val;
      };
      priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);

      for (const auto head : lists) {
        if (head) pq.emplace(head);
      }

      ListNode* newHead = nullptr;
      ListNode* prev = nullptr;
      while (!pq.empty()) {
        auto least = pq.top();
        pq.pop();
        if (least->next) pq.emplace(least->next);

        auto temp = new ListNode(least->val);
        if (!newHead) newHead = temp;
        if (prev) prev->next = temp;
        prev = temp;
      }

      return newHead;
    }
};