class Solution {
    int size;
    int util(const vector<int> &prices,int i,int sum,bool flag) {
        if (i >= size) {
            return sum;
        }
        
        int result = INT_MIN;
        //buy 
        if (!flag) {
            result = util(prices,i+1,sum-prices[i],true);
        } else {
            // sell
            result = max(result,util(prices,i+1,sum+prices[i],false));
        }
        
        // do nothing
        result = max(result,util(prices,i+1,sum,flag));
        return result;
    }
public:
    int maxProfit(vector<int>& prices) {
        size = prices.size();
        return util(prices,0,0,false);
    }
};