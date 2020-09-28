class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int size = nums.size();
        int left = 0;
        int prod = 1;
        int result = 0;
        for(int right=0;right < size;++right) {
            prod *= nums[right];
            while(left < right && prod >= k) {
                prod /= nums[left];
                ++left;
            }
            if (prod < k) {
                result += right-left+1;
            }
        }
        return result;
    }
};