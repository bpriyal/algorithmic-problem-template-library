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
        printf("%d,%d\n",i,j);
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
        /*row = heights.size();
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
        
        return _min;*/
        int si = heights.size(), sj = heights[0].size();
    vector<vector<int>> eff(si, vector<int>(sj, 1000000));
    vector<int> dir{0, 1, 0, -1, 0};
    auto comp = [&](const array<int, 3> &p1, const array<int, 3> &p2) { return p1[0] >= p2[0]; };
    priority_queue<array<int, 3>, vector<array<int, 3>>, decltype(comp)> pq(comp);
    eff[0][0] = 0;
    pq.push({0, 0, 0});
    while(!pq.empty()) {
       auto [e, i, j] = pq.top();
       pq.pop();
       if (i == si - 1 && j == sj - 1)
           break;
       for (auto d = 0; d < 4; ++d) {
           int x = i + dir[d], y = j + dir[d + 1];
           if (x >= 0 && y >= 0 && x < si && y < sj) {
               int new_eff = max(eff[i][j], abs(heights[i][j] - heights[x][y]));
               if (new_eff < eff[x][y]) {
                   eff[x][y] = new_eff;
                   pq.push({new_eff, x, y});
               }
           }
        }
    }
    return eff[si - 1][sj - 1];
    }
};