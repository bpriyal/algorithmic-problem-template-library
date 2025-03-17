class Solution {
    vector<int> cache;
public:
    Solution(vector<int>& w) {
      int smallest = INT_MAX;
      int sum = 0;

      for (const auto& num : w) {
        sum += num;
        smallest = min(smallest, num);
      }

      for (int i = 0; i < w.size(); ++i) {
        int freq = w[i] / smallest;
        for (int f = 0; f < freq; ++f) cache.emplace_back(i);
      }
    }
    
    int pickIndex() {
      return cache[rand() % cache.size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */