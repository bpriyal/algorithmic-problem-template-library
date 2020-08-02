class Solution {
    vector<int> findEndZeros(const vector<vector<int>> &grid) {
        vector<int> temp;
        int size = grid[0].size();
        int zeros;
        for(auto &row:grid) {
            int i = size - 1;
            zeros = 0;
            while(i >= 0 && row[i] == 0) {
                ++zeros;
                --i;
            }
            temp.push_back(zeros);
        }
        return temp;
    }
    
    int swaps(vector<int> &temp) {
        int size = temp.size();
        int count = 0;
        for(int i =0;i<size;++i) {
            if (temp[i] < size-i-1) {
                int j = i;
                while(j < size && temp[j] < size-i-1) {
                    ++j;
                }
                if (j == size) {
                    return -1;
                }
                while(i<j) {
                    swap(temp[j],temp[j-1]);
                    --j;
                    ++count;
                }
            }
        }
        return count;
    }
public:
    int minSwaps(vector<vector<int>>& grid) {
        int size = grid.size();
        vector<int> temp = findEndZeros(grid);
        return swaps(temp);
    }
};