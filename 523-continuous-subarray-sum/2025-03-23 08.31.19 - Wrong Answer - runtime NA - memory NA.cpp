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

        auto it = modToIdxMap.find(mod);
        if (it != modToIdxMap.end()) {
          if (i - it->second > 1) return true;
        } else {
          modToIdxMap.try_emplace(mod, i);
        }
      }
      return false;
    }
};