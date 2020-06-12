class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        int p0 = 0;
        int p = 0;
        int p2 = size-1;
        while (p <= p2) {
            if (nums[p] == 2) {
                swap(nums[p],nums[p2]);
                --p2;
            } else if (nums[p] == 0) {
                swap(nums[p],nums[p0]);
                ++p;
                ++p0;
            } else {
                ++p;
            }
        }
    }
};