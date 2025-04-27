class Solution {
public:
    int pivotIndex(vector<int>& nums) {
      int size = nums.size();
      int sum = 0, leftSum = 0;
      for (int i = 0; i < size; ++i) sum += nums[i];
      for (int i = 0; i < size; ++i) {
        if (leftSum == sum - leftSum - nums[i]) return i;
        leftSum += nums[i];
      }
      return -1;
    }
};