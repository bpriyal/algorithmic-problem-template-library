class Solution {
    int size;
    bool util(vector<int>& nums, int set1, int set2, int i) {
        if (i == size) return set1 == set2;
        
        bool a = util(nums, set1 + nums[i], set2, i + 1);
        bool b = util(nums, set1, set2 + nums[i], i + 1);
        
        return a || b;
    }
public:
    bool canPartition(vector<int>& nums) {
        size = nums.size();
        
        return util(nums, 0, 0, 0);
    }
};