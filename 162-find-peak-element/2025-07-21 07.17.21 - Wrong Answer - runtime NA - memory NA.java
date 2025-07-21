class Solution {
    public int findPeakElement(int[] nums) {
        // int prev;
        // int curr;

        // for (int i = 0; i < nums.length - 1; ++i) {
        //     if (nums[i] > nums[i + 1]) return i;
        // }
        // return nums.length - 1;
        int s = search (1, nums.length - 1, nums);
        return s;
    }

    int search (int l, int r, int[] nums) {
        int mid = l + (r - l) / 2;
        if (l > r) return nums.length - 1;
        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) return mid;
        int left = search (l, mid - 1, nums);
        int right = search (mid + 1, r, nums);
        if (left > right) return left;
        return right;
    }
}