class Solution {
    vector<vector<int>> cache;
    int check(int row,int col,const vector<vector<char>>& board,int rsize,int csize) {
        if (row == 0 || row == rsize || col == 0 || col == csize || board[row][col == 'O']) { 
            cache[row][col] = 2;
            return 2;
        }
        //cache[row][col] = 1; //visited
        int result;
        if (board[row-1][col] == 'O') {
            if (cache[row-1][col] != -1) {
                if (cache[row-1][col] == 2){
                    cache[row][col] = 2;
                    return 2;
                }
            } else {
                result = check(row-1,col,board,rsize,csize);
                if (result == 2) {
                    cache[row][col] = 2;
                    return cache[row][col];
                }
            }
        }
        if (board[row+1][col] == 'O') {
            if (cache[row+1][col] != -1) {
                if (cache[row+1][col] == 2){
                    cache[row][col] = 2;
                    return 2;
                }
            } else {
                result = check(row+1,col,board,rsize,csize);
                if (result == 2) {
                    cache[row][col] = 2;
                    return cache[row][col];
                }
            }
        }
        if (row == 3 && col == 3) cout<<board[row][col-1]<<","<<cache[row][col-1]<<endl;
        if (board[row][col-1] == 'O') {
            if (row == 3 && col == 3) cout<<"***"<<cache[row][col-1]<<endl;
            if (cache[row][col-1] != -1) {
                if (cache[row][col-1] == 2){
                    cache[row][col] = 2;
                    return 2;
                }
            } else {
                result = check(row,col-1,board,rsize,csize);
                if (result == 2) {
                    cache[row][col] = 2;
                    return cache[row][col];
                }
            }
        }
        if (board[row][col+1] == 'O') {
            if (cache[row][col+1] != -1) {
                if (cache[row][col+1] == 2){
                    cache[row][col] = 2;
                    return 2;
                }
            } else {
                result = check(row,col+1,board,rsize,csize);
                if (result == 2) {
                    cache[row][col] = 2;
                    return cache[row][col];
                }
            }
        }
        cache[row][col] = 0;
        return 0;
    }
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0) return;
        int row = board.size() - 1;
        int col = board[0].size() - 1;
        cache.resize(row+1);
        for(int i = 0;i<= row;++i) cache[i].resize(col+1,-1);
        
        for (int i = 1;i<row;++i) {
            for(int j = 1;j<col;++j) {
                if (board[i][j] == 'O') {
                    if (cache[i][j] != -1) {
                       if (cache[i][j] == 0) board[i][j] = 'X';
                    } else {
                        if (check(i,j,board,row,col) == 0) board[i][j] = 'X';
                    }
                }
            }
        }
         for (int i = 0;i<=row;++i) {
            for(int j = 0;j<=col;++j) {
                cout<<cache[i][j]<<" ";
            }
            cout<<"\n";
         }
        
    }
};