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
       int randomNumber = (rand() % prefixSum.size()) * prefixSum.back();
        cout << randomNumber << endl;
       for (int i = prefixSum.size() - 1; i >= 0; --i) {
        if (randomNumber <= prefixSum[i]) return i;
       }
       return -1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */