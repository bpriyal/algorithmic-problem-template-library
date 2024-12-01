class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSubArray = nums[0];
        int maxSA = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            currSubArray = max(nums[i], currSubArray + nums[i]);
            maxSA = max(maxSA, currSubArray);
        }
        return maxSA;
    }
};