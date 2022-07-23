class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        
        vector<pair<int, int>> cache;
        
        for(int i = 0; i < size; ++i) {
            cache.push_back({nums[i], i});
        }
        
        sort(cache.begin(), cache.end(), [](const auto &a, const auto &b){
           return  a.first < b.first;
        });
        
        int i = 0;
        int j = size - 1;
        
        while (i < j) {
            int sum = cache[i].first + cache[j].first;
            
            if (sum == target) return {cache[i].second, cache[j].second};
            else if (sum < target) ++i;
            else --j;
        }
        
        return {-1, -1};
    }
};