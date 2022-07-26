class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        int fr = 0;
        int lc = col - 1;
        int lr = row - 1;
        int fc = 0;
        
        vector<int> result;
        
        while (true) {
            for(int i = fc; i <= lc; ++i) {
                result.push_back(matrix[fr][i]);
            }
            
            if (fc > lc) break;
            ++fr;
            
            for(int i = fr; i < lr; ++i) {
                result.push_back(matrix[i][lc]);
            }
            if (fr >= lr) break;
            --lc;
            
            for(int i = lc + 1; i >= fc; --i) {
                result.push_back(matrix[lr][i]);
            }
            if (lc + 1 < fc) break;
            --lr;
            
            for(int i = lr; i >= fr; --i) {
                result.push_back(matrix[i][fc]);
            }
            if (lr < fr) break;
            ++fc;
        }
        
        return result;
    }
};