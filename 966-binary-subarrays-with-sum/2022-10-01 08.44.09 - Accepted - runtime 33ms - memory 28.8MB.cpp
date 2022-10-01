class Solution {
    int size;
    int atMost(vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        
        int left = 0, right = 0, result = 0;
        
        for (right = 0; right < size; ++right) {
            goal -= nums[right];
            
            while (goal < 0) {
                goal += nums[left];
                ++left;
            }
            
            result += right - left + 1;
        }
        
        return result;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        size = nums.size();
        
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};