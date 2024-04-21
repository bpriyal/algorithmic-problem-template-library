class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int size = nums.size();
        int firstOccurence = INT_MAX, lastOccurence = INT_MIN;
        int l = 0, r = size - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                firstOccurence = min(firstOccurence, mid);
                r = mid - 1;
            }
            else if (nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }

        l = 0, r = size - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                lastOccurence = max(lastOccurence, mid);
                l = mid + 1;
            }
            else if (nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        if (lastOccurence == INT_MIN || firstOccurence == INT_MAX) return false;
        return static_cast<double>(lastOccurence - firstOccurence + 1) > (size / 2.0);
    }
};