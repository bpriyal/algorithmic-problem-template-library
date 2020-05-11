class Solution {
public:
    int rows,cols;
    void floodFill_util(vector<vector<int>>& image,const int& sr,const int& sc,const int& oldColor,const int& newColor){
        image[sr][sc] = newColor;
        if (sc-1 >= 0 && image[sr][sc-1] == oldColor) floodFill_util(image,sr,sc-1,oldColor,newColor);
        if (sc+1 < cols && image[sr][sc+1] == oldColor) floodFill_util(image,sr,sc+1,oldColor,newColor);
        if (sr-1 >= 0 && image[sr-1][sc] == oldColor) floodFill_util(image,sr-1,sc,oldColor,newColor);
        if (sr+1 < rows && image[sr+1][sc] == oldColor) floodFill_util(image,sr+1,sc,oldColor,newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        rows = image.size();
        cols = image[0].size();
        int oldColor = image[sr][sc];
        if (newColor == oldColor) return image;
        floodFill_util(image,sr,sc,oldColor,newColor);
        return image;
    }
};