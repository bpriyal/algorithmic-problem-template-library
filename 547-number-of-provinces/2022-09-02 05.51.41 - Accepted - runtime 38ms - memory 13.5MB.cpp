class Solution {
    int row, col;
    vector<bool> visited;
    
    void util(vector<vector<int>>& isConnected, int i) {
        
        visited[i] = true;
        
        for (int j = 0; j < col; ++j) {
            if (isConnected[i][j] == 1 && !visited[j]) {
                util(isConnected, j);
            }
        }
    } 
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        row = isConnected.size();
        col = isConnected[0].size();
        int result = 0;
        
        visited.resize(row, false);
        
        for (int i = 0; i < row; ++i) {
            if (!visited[i]) {
                ++result;
                util(isConnected, i);
            }
        }
        
        return result;
    }
};