#include<algorithm> 
class Solution {
public:
    vector<vector<int>> adj;
    int util(int n,const vector<vector<int>>& edges,const vector<bool>& hasApple,const int& root,const int &d,const int& last) {
        int result = 0;
        for (auto &x:adj[root]) {
            if (x != last) {
                int temp = util(n,edges,hasApple,x,d+1,root);
                if (temp) result = result + temp - d;
            }
        }
        return result || hasApple[root]? result+d:0;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        adj.resize(n);
        for (auto &x:edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        return util(n,edges,hasApple,0,0,-1)*2;
    }
};