class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> cache;
        
        for(int num:nums) {
            ++cache[num];
            if (cache[num] > 1) {
                return true;
            }
        }
        
        return false;
    }
};