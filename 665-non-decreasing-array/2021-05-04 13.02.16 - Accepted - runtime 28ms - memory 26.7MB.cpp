class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int size = nums.size();
        int count = 0;
        
        for(int i = 0;i < size - 1 && count <= 1;++i) {
            if (nums[i+1] < nums[i]) {
                ++count;
                
                if (i-1 < 0 || nums[i-1] <= nums[i+1]) {
                    nums[i] = nums[i+1];
                } else {
                    nums[i+1] = nums[i];
                }
            }
        }
        
        return count <= 1;
    }
};