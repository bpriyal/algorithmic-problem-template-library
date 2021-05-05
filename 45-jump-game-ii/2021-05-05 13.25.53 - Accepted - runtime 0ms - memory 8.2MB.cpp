class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        int i = size - 1;
        int result = 0;
        while (i > 0) {
            int j;
            for(j = 0;j < i;++j) {
                if (nums[j] >= i-j) {
                    ++result;
                    i = j;
                    break;
                }
            }  
        }
        
        return result;
    }
};