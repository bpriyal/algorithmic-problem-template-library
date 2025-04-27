class Solution {
    bool isPossible(const vector<int>& ribbons, int k, int cutSize) {
      for (auto ribbon : ribbons) {
        k -= ribbon / cutSize;
      }
      return k <= 0;
    }
public:
    int maxLength(vector<int>& ribbons, int k) {
      int left = 1;
      int right = *max_element(ribbons.begin(), ribbons.end());
      while (left <= right) {
        int mid = left + (right - left) / 2;
        if (isPossible(ribbons, k, mid)) left = mid + 1;
        else right = mid - 1;
      }
      return left - 1;
    }
};