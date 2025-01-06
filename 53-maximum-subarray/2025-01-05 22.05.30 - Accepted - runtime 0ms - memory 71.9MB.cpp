class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int runSum = 0;
        int minEle = 0;
        int result = INT_MIN;
        for (int i = 0; i < size; ++i) {
            runSum += nums[i];
            result = max(result, runSum - minEle);
            minEle = min(minEle, runSum);
        }
        return result;
    }
};