class Solution {
    bool modifiedBinary(const vector<int> &nums,int target,int l,int h) {
        if (l > h) {
            return false;
        }
        int mid = l + (h-l)/2;
        if (nums[mid] == target) {
            return true;
        }
        if (nums[0] < nums[mid]) {
            if (target >= nums[l] && target < nums[mid]) {
                return modifiedBinary(nums,target,l,mid-1);
            }
            return modifiedBinary(nums,target,mid+1,h);
        }
        if (target > nums[mid] && target <= nums[h]) {
            return modifiedBinary(nums,target,mid+1,h);
        }
        return modifiedBinary(nums,target,l,mid-1);
    }
public:
    bool search(vector<int>& nums, int target) {
        int size = nums.size();
        int l = 0;
        int h = size - 1;
        return modifiedBinary(nums,target,l,h);
    }
};