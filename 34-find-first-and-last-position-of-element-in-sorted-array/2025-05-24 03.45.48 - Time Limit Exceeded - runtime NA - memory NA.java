class Solution {
    public int[] searchRange(int[] nums, int target) {
        //stop left when nums[i] == target and nums[i-1] != target 
        //stop right when nums[i] == target and nums[i+1] != target

        int left = binSearch (nums, target, true);
        if (left == -1) return new int[] { -1, -1 };
        int right = binSearch (nums, target, false);
        return new int[] { left, right };
    }

    int binSearch (int[] nums, int target, boolean checkLeft) {
        int n = nums.length;
        int begin = 0;
        int end = n - 1;

        while (begin <= end) {
            int mid = begin + (end - begin)/2;
            if (nums[mid] == target) {
                if (checkLeft) { //finding firstOccurrence
                    if (mid == begin || nums[mid - 1] != target) return mid;
                    end = mid;
                } else { //finding last occurrence
                    if (mid == end || nums[mid + 1] > target) return mid;
                    begin = mid;
                }
            } else if (nums[mid] != target) { //target lies in right half of array
                begin = mid + 1;
            }
            else { //target lies in left half of the array
                end = mid - 1;
            }
        }
        return -1;
    }
}