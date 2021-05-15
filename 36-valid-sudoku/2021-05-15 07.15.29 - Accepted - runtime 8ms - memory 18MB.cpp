class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9] = {0};
        int col[9][9] = {0};
        int block[9][9] = {0};
        
        for(int i = 0;i < 9;++i) {
            for(int j = 0;j < 9;++j) {
                if (board[i][j] != '.') {
                   // printf("i:%d||j:%d||val:%d\n",i,j,board[i][j]-'0');
                    int x = 3*(i/3)+j/3;
                    int y = board[i][j]-'0' - 1;
                    ++row[i][y];
                    ++col[j][y];
                    ++block[x][y];
                    
                    if (row[i][y] > 1 || col[j][y] > 1 || block[x][y] > 1) {
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
};