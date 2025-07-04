class Solution {
    public int[] productExceptSelf(int[] nums) {
        int size = nums.length;
        int[] runSumF = new int[size];
        int[] runSumB = new int[size];

        int mult = 1;
        for (int i = 0; i < size; ++i) {
            mult *= nums[i];
            runSumF[i] = mult;
        }
        mult = 1;
        for (int i = size - 1; i >= 0; --i) {
            mult *= nums[i];
            runSumB[i] = mult;
        }
        int[] ans = new int[size];
        ans[0] = runSumB[1];
        ans[size - 1] = runSumF[size - 2];
        for (int i = 1; i < size - 1; ++i) {
            ans[i] = runSumF[i-1]*runSumB[i+1];
        }
        return ans;
    }
}