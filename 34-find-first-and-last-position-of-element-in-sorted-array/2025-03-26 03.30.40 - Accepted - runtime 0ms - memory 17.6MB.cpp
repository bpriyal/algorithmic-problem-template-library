class Solution {
    // int first = INT_MAX, second = INT_MIN;
    // int util(const vector<int>& nums, int target, int left, int right) {
    //   while (left <= right) {
    //     int mid = left + (right - left) / 2;
    //     if (nums[mid] == target) {
    //       auto leftResult = util(nums, target, left, mid - 1);
    //       auto rightResult = util(nums, target, mid + 1, right);
    //       first = leftResult != -1 ? min({first, leftResult, mid}) : min(first, mid);
    //       second = rightResult != -1 ? max({second, rightResult, mid}) : max(second, mid);
    //       return mid;
    //     } else if (nums[mid] > target) {
    //       right = mid - 1;
    //     } else left = mid + 1;
    //   }
    //   return -1;
    // }

    int findLeftOrRight(const vector<int>& nums, int target, int left, int right, int isFirst) {
      while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
          if (isFirst) {
            if (mid == left || nums[mid - 1] != target) return mid;
            right = mid - 1;
          } else {
            if (mid == right || nums[mid + 1] != target) return mid;
            left = mid + 1;
          }
        } else if (nums[mid] > target) {
          right = mid - 1;
        } else left = mid + 1;
      }
      return -1;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      int size = nums.size();
      // util(nums, target, 0, size - 1);
      // return first == INT_MAX ? vector<int>{-1, -1} : vector<int>{first, second};

      auto leftIdx = findLeftOrRight(nums, target, 0, size - 1, true);
      if (leftIdx == -1) return vector<int>{-1, -1};
      auto rightIdx = findLeftOrRight(nums, target, 0, size - 1, false);

      return vector<int>{leftIdx, rightIdx};
    }
};