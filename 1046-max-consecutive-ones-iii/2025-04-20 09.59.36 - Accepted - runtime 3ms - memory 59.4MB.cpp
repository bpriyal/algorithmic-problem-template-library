class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
      int size = nums.size();
      int left = 0, right = 0;
      int result = INT_MIN;
      int current = 0;
      for (right = 0; right < size; ++right) {
        if (nums[right] == 0) {
          if (k == 0) {
            while (k == 0) {
              if (nums[left] == 0) ++k;
              ++left;
            }
          }
          --k;
        }
        result = max(result, right - left + 1);
      }
      return result;
    }
};