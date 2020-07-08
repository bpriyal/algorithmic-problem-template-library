class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        set<vector<int>> result;
        if (size < 3) return vector<vector<int>>(result.begin(),result.end());
        sort(nums.begin(),nums.end());
        for (int i = 0;i<size-3;++i) {
            int val = -nums[i];
            unordered_map<int,int> cache;
            for(int j = i+1;j<size;++j) {
                if (cache[nums[j]] == 0) {
                    ++cache[val-nums[j]];
                } else {
                    --cache[nums[j]];
                    result.insert({nums[i],nums[j],-(nums[i]+nums[j])});
                }
            } 
        }
        return vector<vector<int>>(result.begin(),result.end());
    }
};