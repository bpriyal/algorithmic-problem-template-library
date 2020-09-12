class Solution {
    vector<vector<int>> result;
    void util(int k,int n,int i,vector<int> &cache) {
        if (k == 0 && n == 0) {
            result.push_back(cache);
            return;
        }
        if (k == 0 || n < 0) {
            return;
        }
        for(int x = i+1;x<10;++x) {
            cache.push_back(x);
            util(k-1,n-x,x,cache);
            cache.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        util(k,n,0,temp);
        return result;
    }
};