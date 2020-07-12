class Solution {
    vector<vector<pair<int,double>>> adj;
    vector<bool> isVisited;
    vector<vector<double>> dp;
    double util(int start,int stop,double prob) {
        if (start == stop) return prob;
       // cout<<dp[start][stop]<<endl;
        if (dp[start][stop] != -1.0) return dp[start][stop];
        isVisited[start] = true;
        double max_ = -1.0;
        //cout<<"here2"<<endl;
        for(int i=0;i<adj[start].size();++i) {
            if (!isVisited[adj[start][i].first]) {
                //cout<<adj[start][i].first<<endl;
                max_ = max(max_,util(adj[start][i].first,stop,prob*adj[start][i].second));
            }
        }
        //cout<<"here3"<<endl;
        isVisited[start] = false;
        dp[start][stop] = max_ < 0 ? 0:max_;
        return dp[start][stop];
    }
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        int size = edges.size();
        adj.resize(n);
        isVisited.resize(n,false);
        dp.resize(n,vector<double>(n,-1.0));
        for(int i = 0;i<size;++i) {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        return util(start,end,1);
        //cout<<"here"<<endl;
        //return dp[start][end];
    }
};