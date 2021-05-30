class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        set<int> cache;
        int result = 0;
        
        for(int num:nums) {
            cache.insert(num);
        }
        cache.insert(INT_MIN);
        
        for(auto it = cache.begin();it != cache.end();++it) {
            auto temp = it;
            result = max(result,*(++temp) - *it);
        }
        
        return result;
    }
};