class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int size = nums.size();
        int result = 0;
        
        int l = -1, r = -1;
        
        for(int i = 0;i < size;++i) {
            if (nums[i] > right) {
                l = i;
            }
            
            if (nums[i] >= left) {
                r = i;
            }
            
            result += r-l;
        }
        
        return result;
    }
};