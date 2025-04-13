class Solution {
    vector<int> prefixSum;
public:
    Solution(vector<int>& w) {
      for (const int& num : w) {
        if (prefixSum.empty()) prefixSum.emplace_back(num);
        else prefixSum.emplace_back(prefixSum.back() + num);
      }
    }
    
    int pickIndex() {
       double randNum = static_cast<double>(rand()) / RAND_MAX;
       double target = randNum * prefixSum.back();
       for (int i = 0; i < prefixSum.size(); ++i) {
        if (target <= prefixSum[i]) return i;
       }
       return -1;
      //  return lower_bound(begin(prefixSum), end(prefixSum), target) - begin(prefixSum);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */