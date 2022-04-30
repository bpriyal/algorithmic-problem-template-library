class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        
        int l = 0, mid = 0;
        int h = nums.size() - 1;
        
        while (l < h) {
            mid = l + (h-l)/2;
            
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return -1;
    }
};