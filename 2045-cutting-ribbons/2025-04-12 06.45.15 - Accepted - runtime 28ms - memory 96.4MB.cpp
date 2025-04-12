class Solution {
    int size;
    bool isPossible(const vector<int>& ribbons, int k, int x) {
      int ribbonsOfSizeX = 0;
      for (const int& ribbon : ribbons) {
        ribbonsOfSizeX += ribbon / x;
      }
      return ribbonsOfSizeX >= k;
    }
public:
    int maxLength(vector<int>& ribbons, int k) {
      size = ribbons.size();
      int left = 1, right = *max_element(ribbons.begin(), ribbons.end());

      while (left <= right) {
        int mid = left + (right - left) / 2;
        if (isPossible(ribbons, k, mid)) left = mid + 1;
        else right = mid - 1;
      }
      return left - 1;
    }
};