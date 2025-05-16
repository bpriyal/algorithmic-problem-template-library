class Solution {
    public void moveZeroes(int[] nums) {
        int count0 = 0;
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] == 0) {
                count0++;
            }
            else {
                if (count0 > 0) {
                    nums[i-count0] = nums[i];
                    nums[i] = 0;
                    // count0--;
                }
            }
        }
    }
}