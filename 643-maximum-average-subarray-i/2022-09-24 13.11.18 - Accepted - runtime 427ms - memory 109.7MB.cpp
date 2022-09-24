class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        int result = 0;
        int size = nums.size();
        
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
        }
        
        result = sum;
        
        for (int i = k; i < size; ++i) {
            sum += nums[i] - nums[i - k];
            result = max(result, sum);
        }
        return static_cast<double>(result)/k;
    }
};