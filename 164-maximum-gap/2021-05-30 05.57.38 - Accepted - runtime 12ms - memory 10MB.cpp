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
        
        auto it = cache.begin();
        auto itn = ++it;
        it = cache.begin();
        
        for(;itn != cache.end();++it,++itn) {
            cout<<*itn-*it<<endl;
            result = max(result,*itn-*it);
        }
        
        return result;
    }
};