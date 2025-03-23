class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
      int size = nums.size();
      unordered_map<int, int> modToIdxMap;
      int sum = 0;

      for (int i = 0; i < size; ++i) {
        sum += nums[i];
        int mod = sum % k;
        if (mod == 0) return true;

        if (auto it = modToIdxMap.find(mod); it != modToIdxMap.end() && (i - it->second > 1)) return true;
      }
      return false;
    }
};