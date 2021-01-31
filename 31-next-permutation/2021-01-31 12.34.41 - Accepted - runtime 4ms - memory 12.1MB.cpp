class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int i;
        for(i = size - 2;i >= 0;i--) {
            if (nums[i] < nums[i+1]) {
                break;
            }
        }
        if (i < 0) {
            reverse(nums.begin(),nums.end());
        } else {
            int j;
            for(j = size-1;j > i;--j) {
                if (nums[j] > nums[i]) {
                    break;
                }
            }
            swap(nums[i],nums[j]);
            reverse(nums.begin()+i+1,nums.end());
        }
    }
};