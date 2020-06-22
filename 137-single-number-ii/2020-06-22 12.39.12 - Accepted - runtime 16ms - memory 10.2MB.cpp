class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> cache;
        for(int i=0;i<nums.size();++i) {
            ++cache[nums[i]];
        }
        for(auto it=cache.begin();it != cache.end();++it) {
            if (it->second == 1) return it->first;
        }
        return 0;
    }
};