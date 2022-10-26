class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int size = nums.size();
        
        vector<int> prefixSum(size + 1, 0);
        
        for (int i = 0; i < size; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        // 0 23 25 29 35 42
        
        for (int i = 0; i <= size - 2; ++i) {
            for (int j = i + 2; j <= size; ++j) {
                if ((prefixSum[j] - prefixSum[i]) % k == 0) return true;
            }
        }
        
        return false;
    }
};