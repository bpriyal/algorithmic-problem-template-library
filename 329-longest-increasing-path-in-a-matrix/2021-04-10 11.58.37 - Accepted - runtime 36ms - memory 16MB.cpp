class Solution {
    vector<vector<int>> dp;
    int row,col;
    
    int util(const vector<vector<int>> &matrix,int i,int j,int last) {
        //cout<<i<<"\t"<<j<<endl;
        if (i >= row || i < 0 || j >= col || j < 0 || last >= matrix[i][j]) {
            return 0;
        }
        //cout<<"here22"<<endl;
        if (dp[i][j] != 0) {
            return dp[i][j] + 1;
        }
        
        int _max = 1;
        int temp = util(matrix,i+1,j,matrix[i][j]);
        _max = max(_max,temp);
        
        temp = util(matrix,i-1,j,matrix[i][j]);
        _max = max(_max,temp);
        
        temp = util(matrix,i,j+1,matrix[i][j]);
        _max = max(_max,temp);
        
        temp = util(matrix,i,j-1,matrix[i][j]);
        _max = max(_max,temp);
        
        dp[i][j] = _max;
        //cout<<_max<<endl;
        return dp[i][j]+1;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        row = matrix.size();
        col = matrix[0].size();
        int result = 1;
        dp.resize(row,vector<int>(col,0));
        
        for(int i = 0;i < row;++i) {
            for(int j = 0;j <col;++j) {
                util(matrix,i,j,-1);
                result = max(dp[i][j],result);
                //cout<<"ofofo"<<result<<endl;
            }
        }
        
        /*for(int i = 0;i < row;++i) {
            for(int j = 0;j <col;++j) {
                cout<<dp[i][j]<<"\t";
            }
            cout<<endl;
        }*/
        
        return result;
    }
};