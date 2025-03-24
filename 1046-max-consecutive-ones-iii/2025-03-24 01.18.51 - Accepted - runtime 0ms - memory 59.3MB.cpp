class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
      int size = nums.size();
      int left = 0,right;
      int count = 0;

      for (right = 0; right < size; ++right) {
        if (nums[right] == 0) --k;
        if (k < 0) {
          if (nums[left] == 0) ++k;
          ++left;
        }
      }
      count = right - left;
      return count;
    }
};