class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int index = 0;

        for (int num : nums) {
            if (num) {
                nums[index++] = num;
            }
        }

        while (index != size) nums[index++] = 0;
    }
};