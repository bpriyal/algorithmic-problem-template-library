class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int size = nums.size();
        for(int i = 0;i < size - 2;++i) {
            for(int j = i+1;j < size -1;++j) {
                for(int k = j+1;k < size;++k) {
                    if (nums[i] < nums[k] && nums[i] < nums[j] && nums[k] < nums[j]) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};