class Solution {
    int bst(const vector<int>& nums, int l, int h, int target) {
        int mid = l + (h-l)/2;
        
        if (h <= l) return -1;
        
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            return bst(nums, mid + 1, h, target);
        } else {
            return bst(nums, l, mid - 1, target);
        }
    } 
public:
    int search(vector<int>& nums, int target) {
        return bst(nums, 0, nums.size()-1, target);
    }
};