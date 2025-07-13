class Solution {
    public int findPeakElement(int[] nums) {
        int size = nums.length;
        if (nums.length == 0) return -1;
        if (nums.length == 1 || nums[0] > nums[1]) return 0;
        if (nums[size - 1] > nums[size - 2]) return size - 1;

        int l = 0;
        int r = size - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]) return mid;
            if (nums[mid] > nums[mid + 1]) r = mid;
            else l = mid + 1;
        }
        return size - 1;
    }
}

// 1 2 3 4 5 6 7 8 9