class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
      int size = nums.size();
      int left = 0, right = 0;
      int result = INT_MIN;

      for (right = 0; right < size; ++right) {
        if (nums[right] == 0) {
          --k;
        }
        if (k < 0) {
          k += 1 - nums[left];
          ++left;
        }
        result = max(result, right - left + 1);
      }
      return result;
    }
};