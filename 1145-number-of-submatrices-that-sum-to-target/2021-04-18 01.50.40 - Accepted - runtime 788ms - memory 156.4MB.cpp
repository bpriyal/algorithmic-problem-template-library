class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        
        for(int i = 0; i < n; i++)
            for(int j = 1; j < m; j++)
                matrix[i][j] += matrix[i][j-1];
        
        int ans = 0;
        unordered_map<int,int>mp;
        
        for(int i = 0; i < m; i++)
            for(int j = i; j < m; j++)
            {
                mp.clear();
                mp[0]++;
                int sum = 0;
                for(int k = 0; k < n; k++)
                {
                    int curr = matrix[k][j];
                    if(i > 0)
                        curr -= matrix[k][i-1];
                    sum+= curr;
                    ans += mp[sum - target];
                    mp[sum]++;
                }
            }
        return ans;
    }
};