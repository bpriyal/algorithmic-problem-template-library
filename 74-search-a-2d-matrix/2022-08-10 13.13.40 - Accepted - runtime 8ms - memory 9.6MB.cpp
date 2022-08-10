class Solution {
    bool searchRow(const vector<int>& num, int size, int target) {
        // cout<<"searchRow:"<<num[0]<<endl;
        int l = 0;
        int r = size - 1;
        
        while (l <= r) {
            int mid = l + (r-l)/2;
            
            if (num[mid] == target) return true;
            else if (num[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        int r = 0;
        int c = col - 1;
        
        while (r < row) {
            int pivotVal = matrix[r][c];
            
            if (pivotVal == target) return true;
            else if (pivotVal < target) ++r;
            else return searchRow(matrix[r], col, target);
        }
        
        return false;
    }
};