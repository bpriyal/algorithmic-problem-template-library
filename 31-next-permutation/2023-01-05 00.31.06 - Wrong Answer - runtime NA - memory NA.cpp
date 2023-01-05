class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int pos = size - 1;
        
        while (pos > 0 && nums[pos - 1] >= nums[pos]) {
            --pos;
        }

        if (pos == 0) { // nums already has highest lexicographical permutation
            reverse(nums.begin(), nums.end());
            return;
        }

        int indexJustGreater;
        int diff = INT_MAX;
        for (int i = pos; i < size; ++i) {
            if (diff > nums[i] - nums[pos - 1]) {
                diff = nums[i] - nums[pos - 1];
                indexJustGreater = i;
            }
        }
        
        swap(nums[pos - 1], nums[indexJustGreater]);

        reverse(nums.begin() + pos, nums.end());
    }
};