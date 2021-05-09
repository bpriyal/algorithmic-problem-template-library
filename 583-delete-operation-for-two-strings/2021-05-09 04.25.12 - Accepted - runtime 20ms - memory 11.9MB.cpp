class Solution {
    int sizea,sizeb;
    vector<vector<int>> dp;
    int util(const string &a,const string &b,int i,int j) {
        if (i >= sizea || j >= sizeb) {
            return 0;
        }
        
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        if (a[i] == b[j]) {
            dp[i][j] =  util(a,b,i+1,j+1) + 1;
        } else {
            dp[i][j] =  max(util(a,b,i+1,j),util(a,b,i,j+1));
        }
        
        return dp[i][j];
    }
public:
    int minDistance(string a, string b) {
        sizea = a.size();
        sizeb = b.size();
        dp.resize(sizea,vector<int>(sizeb,0));
        
        for(int i = 0;i < sizea;++i) {
            for(int j = 0;j < sizeb;++j) {
                if (a[i] == b[j]) {
                    dp[i][j] = (i-1 >= 0 && j-1 >= 0)? dp[i-1][j-1]+1:1;
                } else {
                    dp[i][j] = max(i-1 >= 0? dp[i-1][j]:0,j-1>= 0?dp[i][j-1]:0);
                }
            }
        }
        
        return sizea+sizeb-2*dp[sizea-1][sizeb-1];
    }
};