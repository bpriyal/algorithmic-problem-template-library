struct Comp {
  bool operator()(pair<int, int> p1, pair<int, int> p2) {
    if (p1.first > p2.first) return true;
    if (p1.first == p2.first) return p1.second > p2.second;
    return false;
  }
};

class Solution {
    static constexpr long mod = 1000000007;
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int size = nums.size();
        vector<int> result(size);
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> pq;
        for (int i = 0; i < size; ++i) pq.emplace(nums[i], i);
        for (int op = 0; op < k; ++op) {
          auto [value, index] = pq.top();
          pq.pop();
          value = ((value % mod) * multiplier) % mod;
          pq.emplace(value, index);
        }
        while (!pq.empty()) {
          auto [value, index] = pq.top();
          pq.pop();
          result[index] = value % mod;
        }
        return result;
    }
};