class Solution {
    public int findPeakElement(int[] nums) {
        // int prev;
        // int curr;

        // for (int i = 0; i < nums.length - 1; ++i) {
        //     if (nums[i] > nums[i + 1]) return i;
        // }
        // return nums.length - 1;
        if (nums.length == 0) return -1;
        if (nums.length == 1) return 0;
        if (nums[nums.length - 1] > nums[nums.length - 2])
                return nums.length - 1;
        else if (nums[0] > nums[1])
                return 0;
        int s = search (1, nums.length - 1, nums);
        return s;
    }

    int search (int l, int r, int[] nums) {
        int mid = l + (r - l) / 2;
        if (l > r)
            return -1;
        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) return mid;
        int left = search (l, mid - 1, nums);
        int right = search (mid + 1, r, nums);
        if (left > right) return left;
        return right;
    }
}