class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      int size = nums.size();
      sort(nums.begin(), nums.end());
      vector<vector<int>> result;

      for (int i = 0; i < size - 2; ++i) {
        int j = i + 1;
        int k = size - 1;
        if (nums[i] <= 0 && (i == 0 || nums[i - 1] != nums[i])) {
          while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == 0) {
              result.emplace_back(vector<int>{nums[i], nums[j], nums[k]});
              ++j;
              --k;
              while (j < k && nums[j] == nums[j - 1]) ++j;
            }
            else if (sum < 0) ++j;
            else --k;
          }
        }
      }
      return result;
    }
};