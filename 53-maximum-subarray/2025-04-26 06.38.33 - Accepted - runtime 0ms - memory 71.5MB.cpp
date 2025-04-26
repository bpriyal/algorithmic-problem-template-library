class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int size = nums.size();
      int runSum = 0;
      int minRunSum = 0;
      int maxSubSum = INT_MIN;

      for (int i = 0; i < size; ++i) {
        runSum += nums[i];
        maxSubSum = max(maxSubSum, runSum - minRunSum);
        minRunSum = min(minRunSum, runSum);
      }

      return maxSubSum;
    }
};