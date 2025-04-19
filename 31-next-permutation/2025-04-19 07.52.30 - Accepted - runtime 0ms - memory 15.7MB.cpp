// Find a[i-1] < a[i]; // 123
// Numbers from a[i] -> end are in decending order, find first number > a[i-1]
// Swap a[i-1] & above number
// Reverse all numbers between a[i-1] & end
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      int size = nums.size();
      if (size == 1) return;

      int i = size - 1;
      while (i > 0) {
        if (nums[i - 1] < nums[i]) break;
        --i;
      }

      if (i != 0) {
        int j = size - 1;
        while (j >= i) {
          if (nums[j] > nums[i - 1]) {
            swap(nums[j], nums[i - 1]);
            break;
          }
          --j;
        }
      }
      reverse(nums.begin() + i, nums.end());
    }
};