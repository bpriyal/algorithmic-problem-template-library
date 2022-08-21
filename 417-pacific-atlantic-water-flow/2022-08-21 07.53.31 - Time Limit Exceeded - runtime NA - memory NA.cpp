class Solution {
    int rows, cols;
    
    int util(vector<vector<int>>& heights, int i, int j, int prevHeight) {
        if (i < 0 || j < 0) return 1;
        if (i >= rows || j >= cols) return 2;
        
        if (prevHeight < heights[i][j] || heights[i][j] == -1) return 0;
        
        int currHeight = heights[i][j];
        
        heights[i][j] = -1;
        
        int a = util(heights, i + 1, j, currHeight);
        int b = util(heights, i - 1, j, currHeight);
        int c = util(heights, i, j + 1, currHeight);
        int d = util(heights, i, j - 1, currHeight);
        
        heights[i][j] = currHeight;
        
        bool flowsToPacific = false;
        bool flowsToAtlantic = false;
        
        if (a == 1 || b == 1 || c == 1 || d == 1) flowsToPacific = true;
        if (a == 2 || b == 2 || c == 2 || d == 2) flowsToAtlantic = true;
        
        if ((a == 3 || b == 3 || c == 3 || d == 3) || (flowsToPacific && flowsToAtlantic)) {
            return 3;
        }
        
        if (flowsToPacific) return 1;
        if (flowsToAtlantic) return 2;
        
        return 0;
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();
        
        vector<vector<int>> result;
        
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                if (util(heights, i, j, INT_MAX) == 3) result.push_back({i, j}); 
            }
        }
        
        return result;
    }
};