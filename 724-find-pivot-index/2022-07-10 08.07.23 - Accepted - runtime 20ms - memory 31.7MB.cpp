class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int size = nums.size();
        vector<int> cache(size+1);
        
        cache[0] = 0;
        
        for(int i = 0;i < size;++i) {
            cache[i+1] = cache[i] + nums[i];
        }
        
        for (int i = 1;i <= size; ++i) {
            if (cache[i-1] == cache[size] - nums[i-1] - cache[i-1]) return i - 1;
        }
        
        return -1;
    }
};