class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
      int size = arr.size();
      int left = 0, right = size - 1;

      while (left <= right) {
        int mid = left + (right - left) / 2;
        int missingNumbers = arr[mid] - mid - 1;
        if (missingNumbers < k) left = mid + 1;
        else right = mid - 1;
      }
      return left + k;
    }
};