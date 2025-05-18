class Solution {
    public int maxLength(int[] ribbons, int k) {
      int left = 1;
      int right = max(ribbons);
      return binSearch(ribbons, left, right, k);
    }

// left = 1, right = 9, k = 4, mid = 5
// left = 1, right = 4, k = 4, mid = 2
// left = 3, right = 4, k = 4, mid = 3
// left = 4, right = 4, k = 4, mid = 4
// left = 5

    int binSearch (int[] ribbons, int left, int right, int k) {
      while (left <= right) {
        int mid = left + (right-left)/2;
        if (isPossible(ribbons, k, mid)) left = mid + 1;
        else right = mid - 1;
      }
      return right;
    }

    boolean isPossible (int[] ribbons, int k, int mid) {
      int cuts = 0;
      for (int i : ribbons) {
        cuts += i / mid;
      }
      return cuts >= k;
    }

    int max(int[] piles) {
      int max = piles[0];
      for (int i : piles) {
        if (max < i) max = i;
      }
      return max;
    }
}