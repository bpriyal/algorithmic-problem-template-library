class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int, int> numToIdxMap;

      for (int i = 0; i < nums.size(); ++i) {
        auto it = numToIdxMap.find(target - nums[i]);
        if (it != numToIdxMap.end()) return {i, it->second};
        numToIdxMap.emplace(nums[i], i);
      }

      return {-1, -1};
    }
};