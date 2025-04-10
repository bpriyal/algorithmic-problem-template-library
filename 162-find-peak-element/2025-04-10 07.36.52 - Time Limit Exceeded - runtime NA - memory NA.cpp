class Solution {
public:
    int findPeakElement(vector<int>& nums) {
      int size = nums.size();
      int left = 0, right = size - 1;

      while (left <= right) {
        int mid = left + (right - left) / 2;

        auto isLeftSmaller = mid == 0 || nums[mid - 1] < nums[mid];
        auto isRightSmaller = mid == size - 1 || nums[mid + 1] < nums[mid];

        if (isLeftSmaller && isRightSmaller) return mid;
        else if (isLeftSmaller) left = mid + 1; // go left
        else if (isRightSmaller) right = mid - 1; // go right
      }

      return -1;
    }
};