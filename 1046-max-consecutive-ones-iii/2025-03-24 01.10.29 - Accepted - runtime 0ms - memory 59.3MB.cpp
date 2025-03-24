class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
      int size = nums.size();
      int i = 0, j = 0, K = k;
      int count = 0;

      while (i < size && j < size) {
        if (nums[j] == 1) {
          ++j;
        } else {
          if (k > 0) {
            --k;
            ++j;
          } else {
            count = max(count, j - i);
            while (k == 0) {
              if (nums[i] == 0) {
                ++k;
              }
              ++i;
            }
          }
        }
      }
      count = max(count, j - i);
      return count;
    }
};