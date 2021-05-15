class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        
        int result = 0;
        
        for(int i = 1;i < size;++i) {
            nums[i] = nums[i] + nums[i-1];
        }
        
        for(int i = 0;i < size;++i) {
            for(int j = i+1;j < size;++j) {
                result = max(result,nums[j]-nums[i]);
            }
        }
        
        return result;
    }
};