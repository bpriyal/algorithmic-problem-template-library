class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int> cache;
        int max = INT_MIN;
        for(int num:nums) {
            ++cache[num];
            max = num > max ? num:max; 
        }
        if (max < 0) {
            return 1;
        }
        for(int i = 1;i <= max;++i) {
            if (cache.find(i) == cache.end()) {
                return i;
            }
        }
        return max+1;
    }
};