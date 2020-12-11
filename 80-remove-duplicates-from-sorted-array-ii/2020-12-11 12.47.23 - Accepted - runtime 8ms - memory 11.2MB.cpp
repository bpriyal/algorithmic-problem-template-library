class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1) {
            return size;
        }
        int i = 1;
        int count = 1;
        while(i < size) {
            if (nums[i-1] == nums[i]) {
                ++count;
                if (count > 2) {
                    nums.erase(nums.begin()+i);
                    --size;
                    continue;
                }
                ++i;
            } else {
                count = 1;
                ++i;
            }
        }
        return size;
    }
};