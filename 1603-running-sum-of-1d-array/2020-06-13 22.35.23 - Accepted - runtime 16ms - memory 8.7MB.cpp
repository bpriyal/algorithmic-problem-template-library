class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> result;
        int size = nums.size();
        result.push_back(nums[0]);
        for(int i = 1;i<size;++i) {
            result.push_back(result[i-1] + nums[i]);
        }
        return result;
    }
};