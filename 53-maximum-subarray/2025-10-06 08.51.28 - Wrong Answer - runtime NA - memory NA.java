class Solution {
    public int maxSubArray(int[] nums) {
        int n = nums.length;
        // int[] lastMax = new int[n];
        int currSum = 0;
        int MAX = nums[0];
        for (int i = 0; i < n; ++i) {
            if (currSum + nums[i] > 0) {
                currSum += nums[i];
                if (MAX < currSum) MAX = currSum;
            }
            else {
                currSum = 0;
            }
        }
        return MAX;
    }
}