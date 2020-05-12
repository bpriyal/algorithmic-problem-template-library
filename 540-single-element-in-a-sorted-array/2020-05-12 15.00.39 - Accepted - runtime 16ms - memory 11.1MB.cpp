class Solution {
public:
    int util(const vector<int>& nums,int l,int h) {
        if (l == h) return nums[l];
        int mid = l + (h-l)/2;
        if (mid % 2 == 0) {
            if (nums[mid] == nums[mid+1]) {
                return util(nums,mid+2,h);
            } else if (nums[mid] == nums[mid-1]) {
                return util(nums,l,mid-2);
            } else return nums[mid];
        } else {
            if (nums[mid] == nums[mid+1]) {
                return util(nums,l,mid-1);
            } else if (nums[mid] == nums[mid-1]) {
                return util(nums,mid+1,h);
            } else return nums[mid];
        }
    }
    int singleNonDuplicate(vector<int>& nums) {
        int size = nums.size();
        return util(nums,0,size-1);
    }
};