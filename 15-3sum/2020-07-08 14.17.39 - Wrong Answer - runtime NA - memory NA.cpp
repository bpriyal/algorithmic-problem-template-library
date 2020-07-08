class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> result;
        if (size < 3) return result;
        sort(nums.begin(),nums.end());
        for (int i = 0;i<size;++i) {
            if (i>= 1 && nums[i] == nums[i-1]) continue;
            int val = -nums[i];
            unordered_map<int,int> cache;
            for(int j = i+1;j<size;++j) {
                if (cache[nums[j]] == 0) {
                    ++cache[val-nums[j]];
                } else {
                    --cache[nums[j]];
                    result.push_back({nums[i],nums[j],-(nums[i]+nums[j])});
                }
            } 
        }
        return result;
    }
};