class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        
        sort(nums.begin(), nums.end());
        
        int i = 0;
        int j = size - 1;
        
        while (i < j) {
            int sum = nums[i] + nums[j];
            
            if (sum == target) return {i, j};
            else if (sum < target) ++i;
            else --j;
        }
        
        return {-1, -1};
    }
};