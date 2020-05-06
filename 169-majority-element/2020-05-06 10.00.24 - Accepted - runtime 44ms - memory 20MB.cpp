class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> cache;
        for (auto x:nums) {
            ++cache[x];
        }
        for (auto it=cache.begin();it!=cache.end();++it) {
            if (it->second > nums.size()/2) {
                return it->first;
            }
        }
        return -1;
    }
};