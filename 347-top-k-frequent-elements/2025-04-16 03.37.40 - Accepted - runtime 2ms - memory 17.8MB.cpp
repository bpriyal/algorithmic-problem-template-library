class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      int size = nums.size();
      unordered_map<int, int> numToFreqMap;
      for (int num : nums) ++numToFreqMap[num];

      auto comp = [&](int num1, int num2) -> bool {
        return numToFreqMap[num1] > numToFreqMap[num2];
      };
      priority_queue<int, vector<int>, decltype(comp)> pq(comp);

      for (const auto& [num, freq] : numToFreqMap) {
        if (pq.size() < k) pq.emplace(num);
        else {
          if (numToFreqMap[pq.top()] < freq) {
            pq.pop();
            pq.emplace(num);
          }
        }
      }

      vector<int> result;
      while (!pq.empty()) {
        result.emplace_back(pq.top());
        pq.pop();
      }

      return result;
    }
};