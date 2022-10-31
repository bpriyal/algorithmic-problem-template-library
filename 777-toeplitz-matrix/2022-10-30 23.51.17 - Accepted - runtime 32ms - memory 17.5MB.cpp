class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // check first row elements
        for (int k = 0; k < cols; ++k) {
            int i = 0;
            int j = k;
            int temp = matrix[i][j];
            
            while (i < rows && j < cols) {
                if (matrix[i++][j++] != temp) return false;
            }
        }
        
        // check first column elements
        for (int k = 0; k < rows; ++k) {
            int i = k;
            int j = 0;
            int temp = matrix[i][j];
            
            while (i < rows && j < cols) {
                if (matrix[i++][j++] != temp) return false;
            }
        }
        
        return true;
    }
};