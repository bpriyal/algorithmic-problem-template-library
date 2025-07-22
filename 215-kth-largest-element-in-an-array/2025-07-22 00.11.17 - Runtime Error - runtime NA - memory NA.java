class Solution {
    public int findKthLargest(int[] nums, int k) {
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;
        for (int i : nums) {
            max = Math.max(max, i);
            min = Math.min(min, i);
        } 
        int n = min < 0 ? max - min + 1 : max;
        if (min > 0) min = 0;
        int count[] = new int[n];

        for (int i : nums) {
            count[i - min - 1]++;
        }
        int i = n - 1;
        for (i = n - 1; i >= 0; --i) {
            k -= count[i];
            if (k <= 0) break;
        }
        return i + 1;
    }
}