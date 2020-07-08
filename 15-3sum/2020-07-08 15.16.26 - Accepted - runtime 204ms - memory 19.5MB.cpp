class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> result;
        if (size < 3) return result;
        sort(nums.begin(),nums.end());
        for (int i = 0;i<size-2;++i) {
            if (i >= 1 && nums[i] == nums[i-1]) continue;
            //cout<<"fix:"<<nums[i]<<endl;
            int val = -nums[i];
            int j = i+1;
            int k = size-1;
            while (j<k) {
                if (j > i+1 && nums[j] == nums[j-1]) {
                    ++j;
                    continue;
                }
                int twosum = nums[j] + nums[k];
                if (twosum == val) {
                    result.push_back({nums[i],nums[j],nums[k]});
                    ++j;
                } else if (nums[j] + nums[k] < val) {
                    ++j;
                } else {
                    --k;
                }
            } 
        }
        return result;
    }
};