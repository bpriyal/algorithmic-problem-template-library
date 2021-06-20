class Solution {
public:
    int kInversePairs(int n, int k) {
        int dp[2][k+1];
		
		int mod = 1000000007;
		
		for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j <= k ; j++)
		{
		    if(i==0)  dp[i%2][j] = (j==0);
		    
		    else if(j==0)  dp[i%2][j] = 1;
		    
		    else
		    dp[i%2][j] = ( dp[i%2][j-1] % mod +
		                
		                ( dp[1-i%2][j] - (( max(j-i , 0) == 0) ? 0 : dp[1-i%2][max(j-i,0)-1]) + mod) % mod) % mod;
		}
		return dp[1-n%2][k];
    }
};