class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeros = 0;
        int j = 0;
        int result = INT_MIN;
        for(int i = 0;i < nums.size();++i) {
            if (nums[i] == 0) {
                ++zeros;
            }
            
            if (zeros > k) {
                zeros -= !nums[j];
                ++j;
            }
            
            result = max(result,i-j+1);
        }
        
        return result;
    }
};