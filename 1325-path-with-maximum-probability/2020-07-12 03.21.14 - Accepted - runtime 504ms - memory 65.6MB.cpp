class Solution {
    vector<vector<pair<int,double>>> adj;
    vector<bool> isVisited;
    vector<double> prob;
    double util(int start,int stop) {
        queue<int> q;
        q.push(start);
        prob[start] = 1;
        while(!q.empty()) {
            int temp = q.front();
            q.pop();
            for(int i=0;i<adj[temp].size();++i) {
                if (prob[adj[temp][i].first] < prob[temp]*adj[temp][i].second) {
                    prob[adj[temp][i].first] = prob[temp]*adj[temp][i].second;
                    q.push(adj[temp][i].first);   
                }
            }
        }
        return prob[stop];
    }
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        int size = edges.size();
        adj.resize(n);
        isVisited.resize(n,false);
        prob.resize(n,0.0);
        for(int i = 0;i<size;++i) {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        return util(start,end);
    }
};