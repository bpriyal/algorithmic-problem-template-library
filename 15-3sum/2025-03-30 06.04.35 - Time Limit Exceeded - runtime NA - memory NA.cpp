class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      int size = nums.size();
      sort(nums.begin(), nums.end());
      set<vector<int>> result;

      for (int i = 0; i < size - 2; ++i) {
        int j = i + 1;
        int k = size - 1;
        while (j < k) {
          int sum = nums[i] + nums[j] + nums[k];
          if (sum == 0) result.emplace(vector<int>{nums[i], nums[j], nums[k]});
          if (sum < 0) ++j;
          else --k;
        }
      }

      return vector<vector<int>>(result.begin(), result.end());
    }
};