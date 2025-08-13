class Solution {
    public int findSpecialInteger(int[] arr) {
        int max = 0;
        int size = arr.length;
        int n = size - 1;
        int ans = 0;
        int[] check = {arr[n/4], arr[n/2], arr[3*n/4], arr[n]};
        for (int num : check) {
            int len = binSearch(num, arr, 0, arr.length - 1, false) - binSearch(num, arr, 0, arr.length - 1, true);
            if (len > max) ans = num;
        }
        return ans;
    }

    int binSearch (int target, int[] arr, int left, int right, boolean isLeft) {
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                if (isLeft) {
                    if (mid-1 >= 0 && arr[mid - 1] != target) return mid;
                    else right = mid - 1;
                } else {
                    if (mid+1 < arr.length && arr[mid + 1] != target) return mid;
                    else left = mid + 1;
                }
            } else if (target > arr[mid]) left = mid + 1;
            else right = mid;
        }
        return left;
    }
}

