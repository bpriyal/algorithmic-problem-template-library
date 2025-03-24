class Solution {
    int size;
    int count = 0;
    int K;
     void util(vector<int>& nums, int i, int k, int streak) {
      if (i >= size) count = max(count, streak);
      if (nums[i] == 1) util(nums, i + 1, k, streak + 1);
      else if (nums[i] == 0) {
        if (k > 0) {
          util(nums, i + 1, --k, streak + 1);
        }

        // reset streak
        count = max(count, streak);
        util(nums, i + 1, K, 0);
      }
    }
public:
    int longestOnes(vector<int>& nums, int k) {
      size = nums.size();
      K = k;
      util(nums, 0, k, 0);
      return count;
    }
};