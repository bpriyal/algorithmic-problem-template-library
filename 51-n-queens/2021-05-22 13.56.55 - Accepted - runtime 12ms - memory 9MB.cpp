class Solution {
    unordered_set<int> cols;
    unordered_set<int> diagonal;
    unordered_set<int> anti;
    vector<vector<string>> result;
    
    void backtrack(int n,int row,vector<string> &state) {
        if (row == n) {
            result.push_back(state);
            return;
        }
        for(int j = 0;j < n;++j) {
            if (cols.find(j) != cols.end() || diagonal.find(row-j) != diagonal.end() || anti.find(row+j) != anti.end()) {
                continue;
            }
            cols.insert(j);
            diagonal.insert(row-j);
            anti.insert(row+j);
            state[row][j] = 'Q';
                
            backtrack(n,row+1,state);
                
            cols.erase(j);
            diagonal.erase(row-j);
            anti.erase(row+j);
            state[row][j] = '.';
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        string temp(n,'.');
        vector<string> state(n,temp);
        
        backtrack(n,0,state);
        return result;
    }
};