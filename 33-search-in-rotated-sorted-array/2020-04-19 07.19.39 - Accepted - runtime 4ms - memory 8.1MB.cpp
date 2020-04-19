class Solution {
public:
    int modified_binary(const vector<int> nums,int l,int h,int target) {
        if (l>h) return -1;
        int mid = (l+h)/2;
        if (target==nums[mid]) return mid;
        if (nums[0]<=nums[mid]) {
            if (target>=nums[l] && target<nums[mid]) {
                return modified_binary(nums,l,mid-1,target);
            }
            return modified_binary(nums,mid+1,h,target);
        }
        if (target>nums[mid] && target<=nums[h]) {
            return modified_binary(nums,mid+1,h,target);
        }
        return modified_binary(nums,l,mid-1,target);
    }
    
    int search(vector<int>& nums, int target) {
        int mid;
        int l=0;
        int h=nums.size();
        int result = modified_binary(nums,l,h-1,target);
        return result;
    }
};