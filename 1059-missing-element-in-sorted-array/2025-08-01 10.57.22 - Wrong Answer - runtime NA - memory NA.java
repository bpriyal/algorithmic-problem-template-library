class Solution {
    public int missingElement(int[] nums, int k) {
        int check = nums[0];
        int count = 0;
        int i = 0;
        while (i < nums.length) {
            int n = nums[i];
            if (check != n) count++;
            else i++;
            if (count == k) return check;
            check++;
        }
        if (count < k) {
            check++;
        }
        return check;
    }
}