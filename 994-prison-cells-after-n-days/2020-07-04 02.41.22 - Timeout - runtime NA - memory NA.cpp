class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) { 
        /* TLE
        
        vector<int> temp(cells.begin(),cells.end());
        for(int i = 0;i < N;++i) {
            for(int j = 1;j < 7;++j) {
                if (temp[j-1] == temp[j+1]) {
                    cells[j] = 1;
                } else {
                    cells[j] = 0;
                }
            }
            if (i == 0) {
                cells[0] = cells[7] = 0;
            }
            temp.clear();
            temp = cells;
        }
         
        TLE */
        
        /* With HASH
        
        unordered_map<int,vector<int>> cache;
        vector<int> temp(cells.begin(),cells.end());
        N = (N%14 == 0) ? 14-1:N%14-1;
        for (int i =0;i<14;++i) {
            for (int j = 1;j<7;++j) {
                if (temp[j-1] == temp[j+1]) {
                    cells[j] = 1;
                } else {
                    cells[j] = 0;
                }
            }
            if (i == 0) {
                cells[0] = cells[7] = 0;
            }
            cache[i] = cells;
            temp = cells;
        }
        return cache[N];
        
        with HASH */
        
        /* Without HASH ---> More efficient */
        
        vector<int> temp(cells.begin(),cells.end());
        N = (N%14 == 0) ? 14:N%14;
        for (int i =0;i<N;++i) {
            for (int j = 1;j<7;++j) {
                if (temp[j-1] == temp[j+1]) {
                    cells[j] = 1;
                } else {
                    cells[j] = 0;
                }
            }
            if (i == 0) {
                cells[0] = cells[7] = 0;
            }
            temp = cells;
        }
        return cells;      
    }
};