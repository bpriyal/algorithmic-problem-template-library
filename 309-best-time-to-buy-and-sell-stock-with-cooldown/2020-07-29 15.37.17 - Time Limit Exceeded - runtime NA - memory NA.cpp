class Solution {
    int size;
    int util(int buyPrice,int result,const vector<int>& prices,int i) {
        //printf("buyPrice:%d||result:%d||i:%d\n",buyPrice,result,i);
        if (i >= size) return result;
        if (buyPrice != -1) { /* sell or not sell*/
           //cout<<result<<" "<<i<<endl;
            return max((prices[i] > buyPrice)? util(-1,result+(prices[i]-buyPrice),prices,i+2):INT_MIN,util(buyPrice,result,prices,i+1));
        } else { /* buy or not buy */
            return max(util(prices[i],result,prices,i+1),util(-1,result,prices,i+1));
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        size = prices.size();
        return util(-1,0,prices,0);
    }
};