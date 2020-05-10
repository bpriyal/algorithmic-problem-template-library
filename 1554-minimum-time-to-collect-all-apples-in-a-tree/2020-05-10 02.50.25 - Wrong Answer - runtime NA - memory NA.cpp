class Solution {
public:
    bool util(const vector<bool> hasApple,const vector<vector<int>> edges,int n,int &count,int adj[][2],int root) {
        if (adj[root][0] == -1) return hasApple[root];
        bool ret = false;
        
        for ( int i = adj[root][0];i <= adj[root][1];++i) {
            ++count;
            bool b = util(hasApple,edges,n,count,adj,edges[i][1]);
            if (b) {
                ++count;
                ret = true;
            } else {
                --count;
            }
        }
        if (ret == false) return hasApple[root];
        else return true;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        int rows = edges.size();
        int adj[n][2];
        for (int i=0;i<n;i++) {
            adj[i][0] = adj[i][1] = -1;
        }
        
        for (int i=0;i<rows;++i) {
            if (adj[edges[i][0]][0] == -1) {
                adj[edges[i][0]][0] = i;
            }
            adj[edges[i][0]][1] = i;
        }
        for (int i=0;i<n;i++) {
            cout<<i<<":"<<adj[i][0]<<","<<adj[i][1]<<endl;
        }
        int count = 0;
        util(hasApple,edges,n,count,adj,0);
        return count;
    }
};