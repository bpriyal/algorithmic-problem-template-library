class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int i,j;
        vector<int> cache;
        int size = nums.size();
        if (size == 1) {
            return true;
        }
        bool check =false;
        for (i=0;i<size;++i) {
            if (nums[i] == 1) {
                check = true;
                cache.push_back(i);
            }
        }
        if (!check) return true;
        
        if (cache.size() == 0) {
            if (k ==0) {
                return true;
            } else {
                return false;
            }
        }
        for (i=1;i<cache.size();++i) {
            cout<<cache[i] - cache[i-1]<<endl;
            if (cache[i] - cache[i-1] - 1 < k) {
                return false;
            }
        }
        return true;
    }
};