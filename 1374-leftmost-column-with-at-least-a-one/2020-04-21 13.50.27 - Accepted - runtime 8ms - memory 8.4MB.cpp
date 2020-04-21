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
    int binary_search(BinaryMatrix &binaryMatrix,int l,int h,int row) {
        if (l > h) {
            return -1;
        }
        int mid = (l+h)/2;
        int val = binaryMatrix.get(row,mid);
        if (val == 1) {
            if (mid == 0) return 0;
            if (binaryMatrix.get(row,mid-1) == 1) {
                return binary_search(binaryMatrix,l,mid-1,row);
            }
            return mid;
        } 
        return binary_search(binaryMatrix,mid+1,h,row);      
    }
    
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dim = binaryMatrix.dimensions();
        int row = dim[0];
        int col = dim[1];
        if (row == 0 || col == 0) {
            return -1;
        }
        vector<int> result;
        for (int i=0;i<row;i++) {
            result.push_back(binary_search(binaryMatrix,0,col-1,i));
        }
        int min =INT_MAX;
        for (int i=0;i<row;++i) {
            if (result[i] == -1) {
                continue;
            }
            if (result[i] < min) {
                min = result[i];
            }
        }
        if (min == INT_MAX) {
            return -1;
        }
        return min;
        
    }
};