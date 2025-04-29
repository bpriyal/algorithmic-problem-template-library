class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      int size = nums.size();
      int zeroIdx = 0;
      for (int i = 0; i < size; ++i) {
        if (nums[i] != 0) {
          swap(nums[i], nums[zeroIdx]);
          ++zeroIdx;
        }
      }
    }
};

// 0 1 0 3 12
// 1 0 0 3 12
// 1 3 0 0 12
// 1 3 12 

//  1 2 3