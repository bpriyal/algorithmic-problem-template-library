#include<algorithm> 
class Solution {
public:
    bool util(const vector<bool> hasApple,const vector<vector<int>> edges,int n,int &count,int root) {
        bool ret = false;
        
        for (int i = 0;i<edges.size();++i) {
            if (edges[i][0] == root) {
                ++count;
                bool b = util(hasApple,edges,n,count,edges[i][1]);
                if (b) {
                    ++count;
                    ret = true;
                } else {
                    --count;
                }
            }
        }
        if (ret == false) return hasApple[root];
        else return true;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        int rows = edges.size();
        /*for (int i=0;i<n;i++) {
            cout<<i<<":"<<adj[i][0]<<","<<adj[i][1]<<endl;
        }*/
        int count = 0;
        util(hasApple,edges,n,count,0);
        return count;
    }
};