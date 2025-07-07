class Solution {
    public int pivotIndex(int[] nums) {
        int n = nums.length;
        int[] left = new int[n];
        int pivotInd = -1;
        left[0] = 0;
        for (int i = 1 ; i < n; ++i) {
            left[i] = left[i-1] + nums[i-1];
        }
        if (left[n - 1] == 0) pivotInd = n - 1;
        int sum = 0; // of n - 1
        for (int i = n - 2; i >= 0; --i) {
            sum += nums[i + 1];
            if (sum == left[i]) pivotInd = i;
        }
        return pivotInd;
    }
}