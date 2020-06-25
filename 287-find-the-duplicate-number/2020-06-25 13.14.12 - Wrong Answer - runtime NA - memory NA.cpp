class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        /*sort(nums.begin(),nums.end());
        for(int i = 0;i<nums.size()-1;++i) {
            if (nums[i] == nums[i+1]) return nums[i];
        }
        return -1;*/
        int i,j;
        i = j = nums[0];
        while(true) {
            if (nums[i] == nums[nums[j]]) break;
            i = nums[i];
            j = nums[nums[j]];
        }
        i = nums[i];
        j = nums[0];
        while(true) {
            if(nums[i]==nums[j]) break;
            i = nums[i];
            j = nums[j];
        }
        return nums[i];
    }
};
