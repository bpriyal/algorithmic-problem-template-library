class Solution {
    public boolean increasingTriplet(int[] nums) {
        int n = 0;
        for (int i = 1; i < nums.length; ++i) {
            if (nums[i] > nums[i - 1]) ++n;
            else {
                n = 0;
            }
            if (n == 2) {
                return true;
            }
        }
        return false;
    }
}