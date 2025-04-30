class Solution {
public:
    int findPeakElement(vector<int>& nums) {
      int size = nums.size();
      int left = 0, right = size - 1;

      while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < nums[mid + 1]) left = mid + 1;
        else right = mid;
      }
      return left;
    }
};

// [1, 1, 2, 3]

// [1, 2, 3 ,4 , 5]