class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int pos = 0;
        for(int i = 0;i < size;++i) {
            if (nums[i] != 0) {
                nums[pos++] = nums[i];
            }
        }
        
        for(int i = pos;i < size;++i) {
            nums[i] = 0;
        }
    }
};