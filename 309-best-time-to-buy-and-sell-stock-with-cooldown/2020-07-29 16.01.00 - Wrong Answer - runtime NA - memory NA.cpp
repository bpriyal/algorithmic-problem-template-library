class Solution {
    int size;
    vector<int> dp;
    int util(int buyPrice,int result,const vector<int>& prices,int i) {
        printf("%d %d %d\n",buyPrice,result,i);
        if (i >= size) return result;
        if (dp[i] != -1) return dp[i];
        if (buyPrice != -1) { /* sell or not sell*/
           //cout<<result<<" "<<i<<endl;
            return dp[i] = max((prices[i] > buyPrice)? util(-1,result+(prices[i]-buyPrice),prices,i+2):INT_MIN,util(buyPrice,result,prices,i+1));
        } else { /* buy or not buy */
            return dp[i] = max(util(prices[i],result,prices,i+1),util(-1,result,prices,i+1));
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        size = prices.size();
        dp.resize(size,-1);
        return util(-1,0,prices,0);
    }
};