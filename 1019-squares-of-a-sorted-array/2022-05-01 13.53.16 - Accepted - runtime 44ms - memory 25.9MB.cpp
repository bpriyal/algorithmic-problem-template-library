class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size();
        int left = 0;
        int right = size - 1;
        int pos = size - 1;
        
        vector<int> result(size);
        
        while (left <= right) {
            if (abs(nums[left]) > abs(nums[right])) {
                result[pos] = nums[left]*nums[left];
                --pos;
                ++left;
            } else {
                result[pos] = nums[right]*nums[right];
                --right;
                --pos;
            }
        }
        
        return result;
    }
};