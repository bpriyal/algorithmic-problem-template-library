class Solution {
    public int[] runningSum(int[] nums) {
        // int[] rsum = new int[nums.length];
        // int total = 0;
        for (int i = 1; i < nums.length; ++i) {
            nums[i] = nums[i-1] + nums[i];
        }
        return nums;
    }
}