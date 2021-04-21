class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int size = triangle.size();
        vector<int> cache(triangle.back());
        
        for (int l = size - 2;l >= 0;--l) {
            for (int i = 0;i <= l;++i) {
                cache[i] = min(cache[i],cache[i+1])+triangle[l][i];
            }
        }
        
        return cache[0];
    }
};