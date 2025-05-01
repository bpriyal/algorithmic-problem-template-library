class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
      int size = nums.size();
      nums.emplace_back(upper + 1);
      vector<vector<int>> result;
      for (int i = 0; i <= size; ++i) {
        if (i == 0) {
          if (nums[i] - lower >= 1) result.emplace_back(vector<int>{lower, nums[i] - 1});
        } else {
          if (nums[i] - nums[i - 1] > 1) result.emplace_back(vector<int>{nums[i - 1] + 1, nums[i] - 1});
        }
      }
      return result;
    }
};