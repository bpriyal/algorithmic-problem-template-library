class Solution {
    public int rob(int[] nums) {
        int sum1 = 0; int sum2 = 0;
        for (int i = 0; i < nums.length; ) {
            sum1 += nums[i];
            i += 2;
        }
        for (int i = 1; i < nums.length; ) {
            sum2 += nums[i];
            i += 2;
        }
        return Math.max(sum1, sum2);
    }
}