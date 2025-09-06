class Solution {
    public int maxSubArray(int[] nums) {
        int max = Integer.MIN_VALUE;
        int n = nums.length;
        int[] count = new int[n + 1];
        count[0] = max;
        for (int i = 1; i < n + 1; ++i) {
            if (count[i - 1] < 0) {
                if (nums[i - 1] > count[i - 1]) {
                    count[i] = nums[i - 1];
                }
            }
            else {
                    count[i] = count[i - 1] + nums[i - 1];
            }
            max = Math.max(max, count[i]);
        }
        return max;
    }
}