class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int size = nums.size();
        int left = 0, result = 0;
        bool flipped = false;

        for (int right = 0; right < size; ++right) {
            if (nums[right] == 0) {
                if (flipped) {
                    while (nums[left] != 0) ++left;
                    ++left; // to move to next 1
                } else flipped = true;
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};