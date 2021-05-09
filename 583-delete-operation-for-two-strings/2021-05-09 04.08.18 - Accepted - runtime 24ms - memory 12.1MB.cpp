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
        dp.resize(sizea,vector<int>(sizeb,-1));
        
        return sizea+sizeb-2*util(a,b,0,0);
    }
};