class Solution {
    int row, col;
    bool isDeadEnd(const vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= row || j < 0 || j >= col) {
            cout<<"return 1"<<endl;
            return true;
        }
        
        if (grid[i][j] == 1) {
            cout<<"return 2"<<endl;
            return j + 1 >= col || grid[i][j+1] == -1;
        }
        else {
            cout<<"return 3"<<endl;
            return j - 1 < 0 || grid[i][j-1] == 1;
        }
    }
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        
        vector<int> result(col, -1);
        
        for(int k = 0; k < col; ++k) {
            int i = 0;
            int j = k;
            
            cout<<"Starting - i:"<<i<<"j:"<<j<<endl;
            
            while(!isDeadEnd(grid, i, j)) {
                j = grid[i][j] == 1? j + 1 : j - 1;
                ++i;
                
                cout<<"i:"<<i<<"j:"<<j<<endl;
                if (i == row) {
                    result[k] = j;
                    break;
                }
            }
        }
        
        return result;
    }
};