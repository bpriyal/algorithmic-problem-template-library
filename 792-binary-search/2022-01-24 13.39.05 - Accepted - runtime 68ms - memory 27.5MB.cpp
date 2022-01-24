class Solution {
    int bst(const vector<int>& nums, int l, int h, int target,int size) {
        int mid = l + (h-l)/2;
        
        if (h < l || mid > size) return -1;
        
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            return bst(nums, mid + 1, h, target, size);
        } else {
            return bst(nums, l, mid - 1, target, size);
        }
    } 
public:
    int search(vector<int>& nums, int target) {
        return bst(nums, 0, nums.size(), target, nums.size() - 1);
    }
};