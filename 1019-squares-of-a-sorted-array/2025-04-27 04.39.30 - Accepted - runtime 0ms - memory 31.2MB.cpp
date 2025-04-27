class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
      int size = nums.size();
      vector<int> result;
      int firstZeroOrPositiveIndex;
      for (int i = 0; i < size; ++i) {
        if (nums[i] >= 0) {
          firstZeroOrPositiveIndex = i;
          break;
        }
      }
      int negPtr = firstZeroOrPositiveIndex - 1;
      while (negPtr >= 0 || firstZeroOrPositiveIndex < size) {
        int candidate1 = negPtr >= 0 ? nums[negPtr] * nums[negPtr] : INT_MAX;
        int candidate2 = firstZeroOrPositiveIndex < size ? nums[firstZeroOrPositiveIndex] * nums[firstZeroOrPositiveIndex] : INT_MAX;
        if (candidate1 <= candidate2) {
          --negPtr;
          result.emplace_back(candidate1);
        } else {
          ++firstZeroOrPositiveIndex;
          result.emplace_back(candidate2);
        }
      }
      return result;
    }
};