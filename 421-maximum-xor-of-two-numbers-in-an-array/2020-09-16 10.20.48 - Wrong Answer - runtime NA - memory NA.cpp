class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int max_ = INT_MIN;
        for(int i=0;i<nums.size();++i) {
            for(int j=i+1;j<nums.size();++j) {
                max_ = max(max_,nums[i]^nums[j]);
            }
        }
        return max_;
    }
};