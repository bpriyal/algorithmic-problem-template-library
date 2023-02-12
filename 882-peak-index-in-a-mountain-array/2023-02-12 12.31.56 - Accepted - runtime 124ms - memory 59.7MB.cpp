class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int size = arr.size();
        int l = 0, h = size - 1;
        // int result;

        while (l <= h) {
            int mid = l + (h - l) / 2;
            
            if (arr[mid - 1] < arr[mid] &&  arr[mid] < arr[mid + 1]) {
                l = mid;
            } else if (arr[mid - 1] > arr[mid] && arr[mid] > arr[mid + 1]) {
                h = mid;
            } else if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
                return mid;
            }
        }

        return -1;
    }
};