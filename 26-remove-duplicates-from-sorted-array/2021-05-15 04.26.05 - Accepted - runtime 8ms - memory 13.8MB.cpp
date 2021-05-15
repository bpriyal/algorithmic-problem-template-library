class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        int counter = 0;
        
        for(int i = 0;i < size;++i) {
            if (nums[i] != nums[counter]) {
                ++counter;
                nums[counter] = nums[i];
            }
        }
        
        while(counter < size - 1) {
            nums.pop_back();
            ++counter;
        }
        
        return nums.size();
    }
};