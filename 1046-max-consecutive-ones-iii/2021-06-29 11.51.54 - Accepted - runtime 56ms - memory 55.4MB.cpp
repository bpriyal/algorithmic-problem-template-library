class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeros = 0;
        int j = 0;
        int result = INT_MIN;
        //[1,1,1,0,0,0,1,1,1,1,0]
        for(int i = 0;i < nums.size();++i) {
            if (nums[i] == 0) {
                ++zeros;
            }
            
            if (zeros > k) {
                ++j;
                zeros -= !nums[j-1];
            }
            
            result = max(result,i-j+1);
        }
        
        return result;
    }
};