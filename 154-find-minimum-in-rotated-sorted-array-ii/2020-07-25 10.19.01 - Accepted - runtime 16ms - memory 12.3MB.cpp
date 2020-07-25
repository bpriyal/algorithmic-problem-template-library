class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();
        int boundary = size - 1;
        for(int i =0;i<size-1;++i) {
            if (nums[i] > nums[i+1]) {
                boundary = i;
            }
        }
        if (boundary == size - 1) {
            return nums[0];
        } else {
            return nums[boundary+1];
        }
    }
};