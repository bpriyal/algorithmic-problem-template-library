class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       /* unordered_map<int,int> cache;
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
        return max+1;*/
        
        int size = nums.size();
        vector<int> cache(size,-1);
        for(int x:nums) {
            if (x > 0 && x <= size) {
                cache[x-1] = 1;
            }
        }
        for(int i = 0;i<size;++i) {
            if (cache[i] == -1) {
                return i+1;
            }
        }
        return size + 1;
    }
};