class Solution {
    int row, col;
    void utility(vector<vector<int>>& image, int sr, int sc, int color, int currColor) {
        if (sr < 0 || sr >= row || sc < 0 || sc >= col || image[sr][sc] == color || image[sr][sc] != currColor) {
            return;
        }
        
        currColor = image[sr][sc];
        image[sr][sc] = color;
        
        utility(image, sr - 1, sc, color, currColor);
        utility(image, sr + 1, sc, color, currColor);
        utility(image, sr, sc - 1, color, currColor);
        utility(image, sr, sc + 1, color, currColor);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        row = image.size();
        col = image[0].size();
        
        utility(image, sr, sc, color, image[sr][sc]);
        
        return image;
    }
};