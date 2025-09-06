class Solution {
    public int singleNonDuplicate(int[] nums) {
        int n = nums.length;
        if (n == 1) return nums[0];
        if (n == 3) { if (nums[1] == nums[0]) return nums[2]; else return nums[0];}
        int max = n/2 + 1;
        int left = 1;
        int right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mid - 2 >= 0) {
                if (nums[mid - 1] > nums[mid - 2] && nums[mid - 1] < nums[mid])  return nums[mid - 1];
            }
            else if (nums[mid - 1] < nums[mid]) return nums[mid - 1];
            if (nums[mid - 1] > right / 2) left = mid;
            else right = mid;
        }
        return nums[left];
    }
}

