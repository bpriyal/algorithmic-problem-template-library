class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int size = nums.size();
        vector<int> result(size,0);
        
        for(int i = size - 2;i >= 0;--i) {
            result[i] = nums[i] > nums[i+1]? result[i+1]+1:result[i+1];
        }
        
        return result;
    }
};