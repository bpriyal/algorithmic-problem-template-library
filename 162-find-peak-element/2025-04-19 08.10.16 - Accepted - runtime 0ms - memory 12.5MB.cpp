class Solution {
public:
    int findPeakElement(vector<int>& nums) {
      int size = nums.size();
      int left = 0, right = size - 1;
      while (left <= right) {
        int mid = left + (right - left) / 2;
        auto isLeftSmaller = mid == 0 || nums[mid - 1] < nums[mid];
        auto isRightSmaller = mid == size - 1 || nums[mid] > nums[mid + 1];
        if (isLeftSmaller && isRightSmaller) return mid;
        else if (!isLeftSmaller) right = mid - 1;
        else if (!isRightSmaller) left = mid + 1;
      }
      return -1;
    }
};