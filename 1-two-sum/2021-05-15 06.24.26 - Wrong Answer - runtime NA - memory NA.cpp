class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,pair<int,int>> cache;
        int size = nums.size();
        
        for(int i = 0;i < size;++i) {
            cache[nums[i]].first = i;
            ++cache[nums[i]].second;
        }
        
        for(int i = 0;i < size;++i) {
            if (nums[i] >= target) {
                continue;
            }
            int rem = target - nums[i];
            
            if (cache.find(rem) != cache.end()) {
                if (rem == nums[i] && cache[rem].second > 1) {
                    return {i,cache[rem].first};
                } 
                
                if (rem != nums[i]) {
                    return {i,cache[rem].first};
                }
            }
        }
        
        return {0,0};
    }
};