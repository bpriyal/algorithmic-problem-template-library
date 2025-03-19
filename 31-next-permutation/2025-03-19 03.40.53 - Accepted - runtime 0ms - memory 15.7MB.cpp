class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      int size = nums.size();
      int i = size - 1;
      while (i > 0 && nums[i - 1] >= nums[i]) --i;

      if (i > 0) {
        int j = size - 1;
        while (j > i && nums[i - 1] >= nums[j]) --j;
        swap(nums[i - 1], nums[j]);
      }
      reverse(nums.begin() + i, nums.end());
    }
};