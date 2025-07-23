class Solution {
    public int[] searchRange(int[] nums, int target) {
        int l = search (nums, 0, nums.length - 1, target, true);
        if (l == -1) {
            return new int[] {-1,-1};
        }
        int r = search (nums, 0, nums.length - 1, target, false);
        
        return new int[] {l,r};
    }

    int search (int[] nums, int l, int r, int target, boolean isLeft) {
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                if (isLeft && mid > 0 && nums[mid - 1] == target) {
                    r = mid - 1;
                } else if ( (!isLeft) && ((mid + 1) < nums.length) && (nums[mid + 1] == target)) {
                    l = mid + 1;
                } else {
                    return mid;
                }
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return - 1;
    }
}
