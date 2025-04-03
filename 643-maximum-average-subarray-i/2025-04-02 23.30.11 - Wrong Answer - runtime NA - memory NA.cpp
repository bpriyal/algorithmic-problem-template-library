class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
      int size = nums.size();

      int sum = 0;
      for (int i = 0; i < k; ++i) {
        sum += nums[i];
      }

      for (int i = k; i < size; ++i) {
        int newSum = sum + nums[i] - nums[i - k];
        sum = max(sum, newSum);
      }

      return static_cast<double>(sum) / k;
    }
};