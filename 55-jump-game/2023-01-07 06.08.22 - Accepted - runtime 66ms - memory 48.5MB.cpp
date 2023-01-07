class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        int leftMostGoodIndex = size - 1;

        for (int i = size - 2; i >= 0; --i) {
            if (i + nums[i] >= leftMostGoodIndex) {
                leftMostGoodIndex = i;
            }
        }

        return !leftMostGoodIndex;
    }
};