class Solution {
    unordered_map<int, vector<int>> numToIdxMap;
public:
    Solution(vector<int>& nums) {
      for (int i = 0; i < nums.size(); ++i) {
        numToIdxMap[nums[i]].emplace_back(i);
      }
    }
    
    int pick(int target) {
      const auto& indexes = numToIdxMap[target];
      return indexes[rand() % indexes.size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */