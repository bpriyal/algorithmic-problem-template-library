class Solution {
    int row,col;
    vector<vector<int>> dp;
    int util(vector<vector<int>>& heights,int i,int j) {
        if (i < 0 || i >= row || j < 0 || j >= col) {
            return -1;
        }
        return heights[i][j];
    }
    bool isMinPath(vector<vector<int>>& heights,int k,int i,int j) {
        //printf("%d,%d\n",i,j);
        if (i == row-1 && j == col-1) {
            return true;
        }
        int temp;
        dp[i][j] = 1;
        if ((temp = util(heights,i+1,j)) != -1) {
            if (dp[i+1][j] != 1 && abs(heights[i][j] - temp) <= k && isMinPath(heights,k,i+1,j)) {
                dp[i][j] = 0;
                return true;
            }
        }
        if ((temp = util(heights,i-1,j)) != -1) {
            if (dp[i-1][j] != 1 && abs(heights[i][j] - temp) <= k && isMinPath(heights,k,i-1,j)) {
                dp[i][j] = 0;
                return true;
            }
        }
        if ((temp = util(heights,i,j+1)) != -1) {
            if (dp[i][j+1] != 1 && abs(heights[i][j] - temp) <= k && isMinPath(heights,k,i,j+1)) {
                dp[i][j] = 0;
                return true;
            }
        }
        if ((temp = util(heights,i,j-1)) != -1) {
            if (dp[i][j-1] != 1 && abs(heights[i][j] - temp) <= k && isMinPath(heights,k,i,j-1)) {
                dp[i][j] = 0;
                return true;
            }
        }
        dp[i][j] = 0;
        return false;
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        row = heights.size();
        col = heights[0].size();
        int _max = INT_MIN;
        int _min = INT_MAX;
        dp.resize(row,vector<int>(col,0));
        
        for(auto rows:heights) {
            for(auto ele:rows) {
                _max = max(_max,ele);
                _min = min(_min,ele);
            }
        }
        _max = _max - _min;
        _min = 0;
        
        while(_min <= _max) {
            int mid = _min + (_max-_min)/2;
            //cout<<mid<<endl;
            if (isMinPath(heights,mid,0,0)) {
                //cout<<"true"<<endl;
                _max = mid - 1;
            } else {
                //cout<<"false"<<endl;
                _min = mid + 1;
            }
        }
        
        return _min;
    }
};