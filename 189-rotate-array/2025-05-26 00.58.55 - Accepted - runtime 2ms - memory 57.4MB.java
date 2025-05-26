class Solution {
    public void rotate(int[] nums, int k) {
        int n = nums.length;
        int[] newnums = new int[n];
        int j;
        for (int i = 0; i < nums.length; ++i) {
            j = (i + k) % n;
            newnums[j] = nums[i];
        }
        for (int i = 0; i < nums.length; i++) {
            nums[i] = newnums[i];
        }
    }
}