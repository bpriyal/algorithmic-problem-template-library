class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        int size = nums.size();
        sort(nums.rbegin(), nums.rend());
        for (int i = 0; i < size; ++i) {
            if (i == size - 1 || nums[i] != nums[i+1]) return nums[i];
            while (i < size -1 && nums[i] == nums[i + 1]) ++i;
        }
        return -1;
    }
};