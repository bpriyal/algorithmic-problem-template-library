class Solution {
    public int longestOnes(int[] nums, int k) {
        int hold = k;
        int first0ind = -1;
        int windowLen = 0;
        int max = 0;
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] == 0 && first0ind == -1) first0ind = i;
            if (k > 0) {
                if (nums[i] == 0) {
                    windowLen++;
                    k--;
                } else {
                    windowLen++;
                }
            } else { //k is now 0
                if (nums[i] == 0) {
                    i = first0ind++;
                    k = hold;
                    max = Math.max(max, windowLen);
                    windowLen = 0;
                } else {
                    windowLen++;
                }
            }
        }
        max = Math.max(max, windowLen);
        return max;
    }
}