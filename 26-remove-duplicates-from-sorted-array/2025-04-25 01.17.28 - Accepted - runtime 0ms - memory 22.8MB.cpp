class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int size = nums.size();
      int pos = 1;

      for (int i = 1; i < size; ++i) {
        if (nums[i - 1] != nums[i]) {
          nums[pos] = nums[i];
          ++pos;
        }
      }
      return pos;
    }
};