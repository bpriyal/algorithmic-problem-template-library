class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int, int> valToIdxMap;

      for (int i = 0; i < nums.size(); ++i) valToIdxMap.try_emplace(nums[i], i);

      for (int i = 0; i < nums.size(); ++i) {
        auto it = valToIdxMap.find(target - nums[i]);
        if (it != valToIdxMap.end() && it->second != i) return {i, it->second};
      }
      return vector<int>();
    }
};