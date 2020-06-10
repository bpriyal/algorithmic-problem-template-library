class Solution {
public:
    
    int binary_search(const vector<int> &nums,int target,int l,int h) {
        if (l > h) return h+1;
        int mid = l + (h-l)/2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] > target) {
            return binary_search(nums,target,l,mid-1);
        } else {
            return binary_search(nums,target,mid+1,h);
        }
    }
    
    int searchInsert(vector<int>& nums, int target) {
        return binary_search(nums,target,0,nums.size()-1);
    }
};