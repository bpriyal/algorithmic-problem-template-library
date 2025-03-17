class Solution {
    vector<int> prefixSum;
public:
    Solution(vector<int>& w) {
      for (auto num : w) {
        prefixSum.emplace_back(num + (prefixSum.empty() ? 0 : prefixSum.back()));
      }
    }
    
    int pickIndex() {
      double random = rand() / RAND_MAX;
      int target = random * prefixSum.back();
      for (int i = 0; i < prefixSum.size(); ++i) {
        if (target > prefixSum[i]) return i;
      }
      return prefixSum.size() - 1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */