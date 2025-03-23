class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
      int size = nums.size();
      unordered_map<int, int> modToIdxMap;
      int prefixMod = 0;
      modToIdxMap.try_emplace(0, -1);

      for (int i = 0; i < size; ++i) {
        prefixMod = (prefixMod + nums[i]) % k;
        auto it = modToIdxMap.find(prefixMod);
        if (it != modToIdxMap.end()) {
          if (i - it->second > 1) return true;
        } else modToIdxMap.try_emplace(prefixMod, i);
      }

      return false;
    }
};