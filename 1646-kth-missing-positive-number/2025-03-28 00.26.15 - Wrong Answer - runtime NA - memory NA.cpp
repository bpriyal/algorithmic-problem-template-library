class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
      int size = arr.size();
      int left = 0, right = size - 1;
      int mid;

      while (left <= right) {
        mid = left + (right - left) / 2;
        int missingNumbersTillMid = arr[mid] - 1 - mid;
        if (missingNumbersTillMid == k) return arr[mid] - 1;
        if (missingNumbersTillMid > k) right = mid - 1;
        else left = mid + 1;
      }

      return left + k;
    }
};