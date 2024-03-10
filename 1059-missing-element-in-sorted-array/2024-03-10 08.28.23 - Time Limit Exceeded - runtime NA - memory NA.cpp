class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int size = nums.size();
        int l = 0;
        int r = size - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] - nums[0] - mid < k) l = mid;
            else r = mid - 1;
        }
        return nums[0] + k + l;
    }
};

