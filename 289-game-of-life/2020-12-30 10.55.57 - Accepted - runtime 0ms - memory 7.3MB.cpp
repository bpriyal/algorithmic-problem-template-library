class Solution {
    int m,n;
    vector<int> cache = {-1,0,1};
    int numberOfLiveCells(const vector<vector<int>>& board,int i,int j) {
        int liveCells = 0;
        for(int r:cache) {
            for(int c:cache) {
                if ((r || c) && (i+r >= 0 && j+c >= 0 && i+r < m && j+c < n)) {
                    liveCells = board[i+r][j+c] == 1 || board[i+r][j+c] == 3? liveCells + 1 : liveCells;
                }
            }
        }
        return liveCells;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        m = board.size();
        n = board[0].size();
        
        /* 0 -> 2, 1->3    live cell -> dead 3*/
        
        for (int i = 0;i < m;++i) {
            for(int j = 0;j < n;++j) {
                int live = numberOfLiveCells(board,i,j);
                if (board[i][j] == 1 || board[i][j] == 3) {
                    if (live < 2 || live > 3) {
                        board[i][j] = 3;
                    }
                } else {
                    if (live == 3) {
                        board[i][j] = 2;
                    }
                }
            }
        }
        for (int i = 0;i < m;++i) {
            for(int j = 0;j < n;++j) {
                if (board[i][j] == 3) {
                    board[i][j] = 0;
                } else if (board[i][j] == 2) {
                    board[i][j] = 1;
                }
            }
        }
         
    }
};