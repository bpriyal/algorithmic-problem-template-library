class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
      // unordered_map<int, int> numToIdxMap;

      // for (int i = 0; i < nums.size(); ++i) {
      //   auto it = numToIdxMap.find(nums[i]);
      //   if (it != numToIdxMap.end()) {
      //     if (i - it->second <= k) return true;
      //     it->second = i;
      //   } else numToIdxMap.try_emplace(nums[i], i);
      // }
      // return false;

      unordered_set<int> cache;
      for (int i = 0; i < nums.size(); ++i) {
        if (cache.contains(nums[i])) return true;
        cache.emplace(nums[i]);
        if (cache.size() > k) cache.erase(nums[i - k]);
      }
      return false;
    }
};