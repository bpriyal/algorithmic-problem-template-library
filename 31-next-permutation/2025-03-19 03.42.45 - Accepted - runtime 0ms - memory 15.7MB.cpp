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

// While scanning right to left find first number where a[i - 1] < a[i]
// Find number i to size - 1, which is just greater than a[i - i], swap them
// Reverse i to size - 1 to make the descending order ascending.

