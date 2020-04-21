/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dim = binaryMatrix.dimensions();
        int row = dim[0];
        int col = dim[1];
        if (row == 0 || col == 0) {
            return -1;
        }
        int result[row];
        for (int i=0;i<row;++i) {
            result[i] = -1;
        }
        int x=0,y=col-1;
        while (x <= row-1 && y >= 0) {
            int val = binaryMatrix.get(x,y);
            if (val == 1) {
                result[x] = y;
                --y;
            } else {
                ++x;
            }
        }
        int in=INT_MAX;
        for (int i=0;i<row;++i) {
            if(result[i]==-1){
                continue;
            }
            if(result[i] < in) {
                in = result[i];
            }
        }
        if (in == INT_MAX) return -1;
        return in;
    }
};