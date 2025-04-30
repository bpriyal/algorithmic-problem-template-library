class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      priority_queue<int, vector<int>, greater<int>> pq;
      for (int num : nums) {
        if (pq.size() < k) pq.emplace(num);
        else {
          if (pq.top() < num) {
            pq.pop();
            pq.emplace(num);
          }
        }
      }
      return pq.top();
    }
};