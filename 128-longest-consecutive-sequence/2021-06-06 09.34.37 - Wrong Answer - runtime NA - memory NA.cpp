class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> cache(nums.begin(),nums.end());
        int result = INT_MIN;
        
        for(int num:nums) {
            if (cache.find(num-1) == cache.end()) {
                int y = num+1;
                while(cache.find(y) != cache.end()) {
                    ++y;
                }
                //cout<<y<<" "<<num<<endl;
                result = max(result,y-num);
            }
        }
        
        return result;
    }
};