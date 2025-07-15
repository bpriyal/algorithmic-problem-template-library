class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n + 1];
        for (int i = 0; i <= n; ++i) dp[i] = -1;
        // dp[0] = nums [0];
        // dp[1] = nums[1];
        // dp[2] = nums[0] + nums[2];
        int lh = sum (nums, 0, dp);
        int rh = sum (nums, 1, dp);
        return Math.max(lh, rh);
    }

    int sum (int[] nums, int ind, int[] dp) {
        if (ind >= nums.length) return 0;
        if (ind == nums.length - 1 || ind == nums.length - 2) return nums[ind];
        int lh = sum (nums, ind + 2, dp);
        int rh = sum (nums, ind + 3, dp);
        dp[ind] = nums[ind] + Math.max(lh, rh);
        return dp[ind];
    }
}

// 1 2 3 1 4 5 2