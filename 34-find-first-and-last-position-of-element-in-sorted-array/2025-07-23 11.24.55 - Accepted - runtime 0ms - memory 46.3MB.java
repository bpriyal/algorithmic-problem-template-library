class Solution {
    public int[] searchRange(int[] nums, int target) {
        int l = search (nums, 0, nums.length - 1, target, true);
        int [] arr = new int[2];
        if (l == -1) {
            arr[0] = -1;
            arr[1] = -1;
            return arr;
        }
        int r = search (nums, 0, nums.length - 1, target, false);
        
        arr[0] = l;
        arr[1] = r;
        return arr;
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
