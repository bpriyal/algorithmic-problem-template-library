class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (i == 0 && nums[i] != nums[i + 1]) return nums[i];
            if (nums[i] != nums[i + 1] && nums[i] != nums[i - 1]) return nums[i];
            if (i == nums.size() - 1 && nums[i] != nums[i - 1]) return nums[i]; 
        }
        return -1;
    }
};