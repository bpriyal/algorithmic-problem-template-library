class Solution {
    public int maxSubArray(int[] nums) {
        int max = Integer.MIN_VALUE;
        int n = nums.length;
        int prev = max;
        // count[0] = max;
        for (int i = 1; i < n + 1; ++i) {
            if (prev < 0) {
                prev = nums[i - 1];
            }
            else {
                    prev = prev + nums[i - 1];
            }
            max = Math.max(max, prev);
        }
        return max;
    }
}