class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        
        if (row == 0) {
            return false;
        }
        
        int col = matrix[0].size();
        if (col == 0) {
            return false;
        }
        
        int u = 0;
        int d = row;
        
        while(u <= d) {
            int mid = u + (d-u)/2;
            //cout<<mid<<endl;
            if (matrix[mid][col-1] >= target && matrix[mid][0] <= target) {
                //cout<<"this rw"<<endl;
                return std::binary_search(matrix[mid].begin(),matrix[mid].end(),target);
            } else if (matrix[mid][col-1] < target) {
                u = mid+1;
            } else {
                d = mid-1;
            }
        }
        return false;
    }
};