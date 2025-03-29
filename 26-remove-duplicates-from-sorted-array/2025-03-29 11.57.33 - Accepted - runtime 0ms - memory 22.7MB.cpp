class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int size = nums.size();
      int idx = -1;
      nums.emplace_back(INT_MAX);
      for (int i = 0; i < size; ++i) {
        if (nums[i] != nums[i + 1]) {
          ++idx;
          nums[idx] = nums[i];
        }
      }
      return idx + 1;
    }
};