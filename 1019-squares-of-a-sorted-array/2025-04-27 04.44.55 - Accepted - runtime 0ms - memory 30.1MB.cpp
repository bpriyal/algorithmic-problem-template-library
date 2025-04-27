class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
      int size = nums.size();
      vector<int> result(size);
      int left = 0, right = size - 1;

      for (int i = size - 1; i >= 0; --i) {
        if (abs(nums[left]) >= abs(nums[right])) {
          result[i] = nums[left] * nums[left];
          ++left;
        } else {
          result[i] = nums[right] * nums[right];
          --right;
        }
      }
      return result;
    }
};