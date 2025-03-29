class Solution {
public:
    int pivotIndex(vector<int>& nums) {
      int size = nums.size();
      vector<int> prefixSum(size, 0);
      prefixSum[0] = nums[0];

      for (int i = 1; i < size; ++i) {
        prefixSum[i] = nums[i] + prefixSum[i - 1];
      }

      for (int i = 0; i < size; ++i) {
        int leftSum = i == 0? 0 : prefixSum[i - 1];
        int rightSum = prefixSum[size - 1] - prefixSum[i];
        if (leftSum == rightSum) return i;
      }

      return -1;
    }
};