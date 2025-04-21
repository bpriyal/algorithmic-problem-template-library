class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      int size = nums.size();
      // vector<int> dp(size, 1);
      // int result = dp[0];

      // for (int i = 1; i < size; ++i) {
      //   for (int j = 0; j < i; ++j) {
      //     if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
      //   }
      //   result = max(result, dp[i]);
      // }
      // return result;

      vector<int> subsequence;
      subsequence.emplace_back(nums[0]);

      for (int i = 1; i < size; ++i) {
        if (nums[i] > subsequence.back()) {
          subsequence.emplace_back(nums[i]);
        } else {
          for (int j = 0; j < subsequence.size(); ++j) {
            if (subsequence[j] > nums[i]) {
              subsequence[j] = nums[i];
              break;
            }
          }
        }
      }
      return subsequence.size();
    }
};