class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int size = nums.size();
      // vector<int> prefixSum(size, 0);
      // for (int i = 0; i < size; ++i) prefixSum[i] = i == 0? nums[i] : prefixSum[i - 1] + nums[i];
      // int minSum = 0;
      // int maxSum = nums[0];

      // for (int i = 0; i < size; ++i) {
      //   maxSum = max(maxSum, prefixSum[i] - minSum);
      //   minSum = min(minSum, prefixSum[i]);
      // }

      // return maxSum;
      int currentSubArray = nums[0];
      int maxSubArray = nums[0];
      for (int i = 1; i < size; ++i) {
        currentSubArray = max(nums[i], currentSubArray + nums[i]);
        maxSubArray = max(maxSubArray, currentSubArray);
      }
      return maxSubArray;
    }
};