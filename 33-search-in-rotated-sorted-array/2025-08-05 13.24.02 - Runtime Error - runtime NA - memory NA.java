class Solution {
    public int search(int[] nums, int target) {
        int n = nums.length;
        if (nums[0] < nums[n - 1]) {
            // if (target < nums[0] || target > nums[n - 1]) return -1;
            // return binSearch(nums, target);
            return 0;
        }
        int dip = findDip(nums);
        if (target == nums[dip]) return dip;
        if (target > nums[0] && target < nums[dip - 1]) return binSearch(nums, target, 0, dip - 1);
        else return binSearch (nums, target, dip, n - 1);
    }

    int findDip (int[] nums) {
        int left = 0;
        int right = nums.length - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[mid - 1]) return mid;
            if (nums[mid] > nums[right]) left = mid + 1;
            else right = mid;
        }
        return left;
    }

    int binSearch (int[] nums, int target, int left, int right) {
        while (left < right) {
            int mid = left + (right - left)/2;
            if (nums[mid] == target) return mid;
            if (target < nums[mid]) right = mid - 1;
            else left = mid + 1;
        }
        if (nums[left] == target) return left;
        return -1;
    }
}

// 0 1 2 3 4 5 6
// 4 5 6 0 1 2 3

