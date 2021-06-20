class Solution {
    int size;
    bool util(vector<vector<int>> &grid,int level,int i,int j) {
        if (i < 0 || i >= size || j < 0 || j >= size || grid[i][j] == -1) {
            return false;
        }
        
        if (level < grid[i][j]) {
            return false;
        }
        
        if (i == size - 1 && j == size - 1) {
            return true;
        }
        
        int temp = grid[i][j];
        grid[i][j] = -1;
        
        if (util(grid,level,i+1,j) || util(grid,level,i-1,j) ||
            util(grid,level,i,j+1) || util(grid,level,i,j-1)) {
            grid[i][j] = temp;
            return true;
        }
        
        grid[i][j] = temp;
        
        
        return false;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        size = grid.size();
        int l = 0;
        int h = size*size-1;
        
        while (l <= h) {
            int mid = l+(h-l)/2;
            cout<<"mid:"<<mid<<endl;
            if (util(grid,mid,0,0)) {
                cout<<"true"<<endl;
                h = mid - 1;
            } else {
                cout<<"false"<<endl;
                l = mid + 1;
            }
        }
        return l;
    }
};