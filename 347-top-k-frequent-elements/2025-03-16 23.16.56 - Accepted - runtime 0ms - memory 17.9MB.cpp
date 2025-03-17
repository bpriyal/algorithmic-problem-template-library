class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int, int> cache;
      for (const auto& num : nums) ++cache[num];

      auto comp = [&](int p1, int p2) -> bool { return cache[p1] > cache[p2]; };
      priority_queue<int, vector<int>, decltype(comp)> pq(comp);

      for (const auto& [key, value] : cache) {
        if (pq.size() == k) {
          if (cache[pq.top()] < value) {
            pq.pop();
            pq.emplace(key);
          }
        } else {
          pq.emplace(key);
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