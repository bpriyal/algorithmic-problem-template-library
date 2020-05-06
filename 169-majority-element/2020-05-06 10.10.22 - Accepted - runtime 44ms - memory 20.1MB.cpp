class Solution {
public:
    int majorityElement(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
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