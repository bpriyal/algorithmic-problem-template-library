class Solution {
    vector<int> prefix;
public:
    Solution(vector<int>& w) {
      for (int num : w) {
        if (prefix.empty()) prefix.emplace_back(num);
        else prefix.emplace_back(prefix.back() + num);
      }
    }
    
    int pickIndex() {
      double randNum = rand() / RAND_MAX;
      double target = randNum * prefix.back();
      return lower_bound(prefix.begin(), prefix.end(), target) - prefix.begin();
    }
};



/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */