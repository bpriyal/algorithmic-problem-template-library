class Solution {
    public long countFairPairs(int[] nums, int lower, int upper) {
        int n = nums.length;
        int count = 0;
        for (int i = 0; i < n-1; ++i) {
            for (int j = i+1; j < n; ++j) {
                int sum = (nums[i] + nums[j]);
                if (sum >= lower && sum <= upper) {
                    count++;
                }
            }
        }
        return count;
    }
}
