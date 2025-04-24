class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
      unordered_map<int, int> numToIdxMap;

      for (int i = 0; i < nums.size(); ++i) {
        auto it = numToIdxMap.find(nums[i]);
        if (it != numToIdxMap.end()) if (i - it->second <= k) return true;
        numToIdxMap[nums[i]] =  i;
      }

      return false;
    }
};