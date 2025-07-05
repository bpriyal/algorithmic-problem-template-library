class Solution {
    public boolean increasingTriplet(int[] nums) {
        int size = nums.length;
        int min = nums[0];
        int max = Integer.MIN_VALUE;
        boolean maxSet = false;
        
        for (int i = 1; i < size; ++i) {

            if (maxSet && nums[i] > max) {
                return true;
            }

            if (nums[i] <= min) {
                min = nums[i];
            } else if (!maxSet) { // nums[i] > max
                max = nums[i];
                maxSet = true;
            }
        }
        return false;
    }
}