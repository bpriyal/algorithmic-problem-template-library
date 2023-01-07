class Solution {
    int size;
    bool util(const vector<int>& nums, int currPos) {
        if (currPos >= size - 1) return true;

        for (int i = 1; i <= nums[currPos]; ++i) {
            if (util(nums, currPos + i)) return true;
        }

        return false;
    }
public:
    bool canJump(vector<int>& nums) {
        size = nums.size();
        return util(nums, 0);
    }
};