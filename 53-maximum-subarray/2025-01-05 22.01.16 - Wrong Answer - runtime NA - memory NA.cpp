class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int runSum = nums[0];
        int minEle = 0;
        int result = nums[0];
        for (int i = 1; i < size; ++i) {
            runSum += nums[i];
            minEle = min(minEle, runSum);
            result = max(result, runSum - minEle);
        }
        return result;
    }
};