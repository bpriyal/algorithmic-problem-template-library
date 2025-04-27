class Solution {
public:
    int pivotIndex(vector<int>& nums) {
      int size = nums.size();
      vector<int> leftSum(size, 0);
      vector<int> rightSum(size, 0);

      for (int i = 1; i < size; ++i) {
        leftSum[i] = leftSum[i - 1] + nums[i - 1];
      }

      for (int i = size - 2; i >= 0; --i) {
        rightSum[i] = rightSum[i + 1] + nums[i + 1];
      }

      for (int i = 0; i < size; ++i) {
        if (leftSum[i] == rightSum[i]) return i;
      }
      return -1;
    }
};