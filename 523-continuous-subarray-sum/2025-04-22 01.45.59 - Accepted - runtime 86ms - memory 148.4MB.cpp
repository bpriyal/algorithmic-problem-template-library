class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
      unordered_map<int, int> modToIdxMap;
      modToIdxMap.emplace(0, -1);
      int runModSum = 0;
      for (int i = 0; i < nums.size(); ++i) {
        runModSum = (runModSum + nums[i]) % k;
        auto it = modToIdxMap.find(runModSum);
        if (it != modToIdxMap.end() && i - it->second >= 2) return true;
        modToIdxMap.emplace(runModSum, i); 
      }
      return false;
    }
};