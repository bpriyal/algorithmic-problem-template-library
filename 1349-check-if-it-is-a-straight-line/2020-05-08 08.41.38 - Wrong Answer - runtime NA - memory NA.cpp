class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int i,j;
        int size = coordinates.size();
        if (size == 2) return true;
        int y_slope = (coordinates[1][1]-coordinates[0][1]);
        int x_slope = (coordinates[1][0]-coordinates[0][0]);
        for (i=2;i<size;++i) {
            if (x_slope != 0 && y_slope != 0) {
                int y = (coordinates[i][1]-coordinates[i-1][1]);
                int x = (coordinates[i][0]-coordinates[i-1][0]);
                if ((y != y_slope) || (x != x_slope)) {
                    return false;
                }
            } else {
                if (x_slope == 0) {
                    if ((coordinates[i][0] - coordinates[i-1][0]) != 0) return false;
                } else {
                    if ((coordinates[i][1] - coordinates[i-1][1]) != 0) return false;
                }
            }
        }
        return true;
    }
};