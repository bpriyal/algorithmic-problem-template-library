class Solution {
    int size;
    bool isPossible(const vector<int>& nums, int k, int maxElement) {
      int i = 0;
      int selectedElements = 0;
      while (i < size) {
        if (nums[i] <= maxElement) {
          ++selectedElements;
          ++i;
        }
        ++i;
      }
      return selectedElements >= k;
    }
public:
    int minCapability(vector<int>& nums, int k) {
      size = nums.size();
      int left = *min_element(nums.begin(), nums.end());
      int right = *max_element(nums.begin(), nums.end());

      while (left <= right) {
        int mid = left + (right - left) / 2;
        if (isPossible(nums, k, mid)) right = mid - 1;
        else left = mid + 1;
      }
      return left;
    }
};