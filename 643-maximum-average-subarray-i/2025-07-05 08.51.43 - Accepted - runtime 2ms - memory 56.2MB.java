class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int n = nums.length;
        int sum = 0;
        int max;
        for (int i = 0; i < k; ++i) sum += nums[i];
        if (k == n) return (1.0 * sum) / n;
        max = sum;
        for (int i = k; i < n; ++i) {
            sum -= nums[i - k];
            sum += nums[i];
            max = Math.max(sum, max);
        }
        return (1.0 * max) / k;
    }
}