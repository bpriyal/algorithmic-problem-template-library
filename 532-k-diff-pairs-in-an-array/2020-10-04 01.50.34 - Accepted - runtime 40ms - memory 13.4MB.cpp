class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int size = nums.size();
        if (size == 1) {
            return 0;
        }
        
        int count = 0;
        int i = 0;
        unordered_map<int,int> cache;
        
        for(int num:nums) {
            ++cache[num];
        }
        
        if (k == 0) {
            for(auto it:cache) {
                if (it.second > 1) {
                    ++count;
                }
            }
            return count;
        }
        
        sort(nums.begin(),nums.end());
        
        while (i < size) {
            if (cache.find(nums[i]+k) != cache.end()) {
                ++count;
            }
            ++i;
            while(i < size && nums[i] == nums[i-1]) {
                ++i;
            }
        }
        
        return count;
    }
};