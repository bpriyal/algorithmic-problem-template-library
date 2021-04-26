class Solution {
    int result;
    
    void util(const vector<int> &nums,int target) {
        if(target == 0) {
            ++result;
            return;
        }
        
        for(int num:nums) {
            if (num > target) {
                return;
            } else {
                util(nums,target-num);
            }
        }
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        result = 0;
        sort(nums.begin(),nums.end());
        
        util(nums,target);
        
        return result;
    }
};