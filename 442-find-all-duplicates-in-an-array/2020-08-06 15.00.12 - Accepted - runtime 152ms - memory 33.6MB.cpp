class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int size = nums.size();
        vector<int> result;
        for(int x:nums) {
            if (nums[abs(x)-1] >= 0) {
                nums[abs(x)-1] = -nums[abs(x)-1];
            } else {
                result.push_back(abs(x));
            }
        }
        return result;
    }
};