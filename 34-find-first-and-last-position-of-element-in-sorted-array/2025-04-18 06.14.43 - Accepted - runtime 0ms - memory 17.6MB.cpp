class Solution {
    int binarySearch(const vector<int>& nums, int target, bool isFirst) {
      int left = 0, right = nums.size() - 1;
      while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
          if (isFirst) {
            if (mid == 0 || nums[mid - 1] != target) return mid;
            else right = mid - 1;
          } else {
            if (mid == nums.size() - 1 || nums[mid + 1] != target) return mid;
            else left = mid + 1;
          }
        } else if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;
      }
      return -1;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      int size = nums.size();
      auto first = binarySearch(nums, target, true /* isFirst */);
      if (first == -1) return {-1, -1};
      auto last = binarySearch(nums, target, false);
      return {first, last};
    }
};