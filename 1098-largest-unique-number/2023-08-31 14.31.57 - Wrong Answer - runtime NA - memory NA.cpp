class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) return nums[0];
        sort(nums.rbegin(), nums.rend());
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (i == 0 && nums[i] != nums[i + 1]) return nums[i];
            if (i == nums.size() - 1 && nums[i] != nums[i - 1]) return nums[i];
            if (nums[i] != nums[i + 1] && nums[i] != nums[i - 1]) return nums[i]; 
        }
        return -1;
    }
};