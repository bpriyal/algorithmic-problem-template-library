class Solution {
    int rowsize,colsize,time=0;
    bool rot(queue<pair<int,int>> &q,int i,int j,vector<vector<int>> &grid,int &fresh) {
        if (i<0||i>=rowsize||j<0||j>=colsize||grid[i][j]!=1) {
            return false;
        }
        q.push({i,j});
        grid[i][j] = 2;
        --fresh;
        return true;
    } 
public:
    int orangesRotting(vector<vector<int>>& grid) {
        rowsize = grid.size();
        colsize = grid[0].size();
        int fresh = 0;
        queue<pair<int,int>> q;
        for(int i = 0;i<rowsize;++i) {
            for(int j = 0;j<colsize;++j) {
                if (grid[i][j] == 1) {
                    ++fresh;
                } else if (grid[i][j] == 2) {
                    q.push({i,j});
                }
            }
        }
        //cout<<"fresh:"<<fresh<<endl;
        while(!q.empty()) {
            int size = q.size();
            //cout<<size<<endl;
            bool flag=false;
            for(int i = 0;i<size;++i) {
                pair<int,int> p = q.front();
                q.pop();
                flag = flag | rot(q,p.first+1,p.second,grid,fresh);
                flag = flag | rot(q,p.first-1,p.second,grid,fresh);
                flag = flag | rot(q,p.first,p.second+1,grid,fresh);
                flag = flag | rot(q,p.first,p.second-1,grid,fresh);
            }
            if (flag) {
                ++time;
            }
        }
        if (fresh != 0) {
            //cout<<fresh<<endl;
            return -1;
        } 
        return time;
    }
};