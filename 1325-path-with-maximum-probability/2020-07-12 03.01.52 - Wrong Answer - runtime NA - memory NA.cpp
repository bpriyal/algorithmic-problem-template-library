class Solution {
    vector<vector<pair<int,double>>> adj;
    vector<bool> isVisited;
    double util(int start,int stop) {
        queue<int> q;
        q.push(start);
        double sum = 1;
        //cout<<"here2"<<endl;
        while(!q.empty()) {
            double max_ = -1.0;
            int temp = q.front();
            //cout<<temp<<endl;
            if (temp == stop) break;
            q.pop();
            for(int i=0;i<adj[start].size();++i) {
                max_ = max(max_,adj[start][i].second);
                q.push(adj[start][i].first);
            }
            //cout<<"max"<<max_<<endl;
            sum = sum * max_;
        }
        return sum;
    }
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        //cout<<"**************"<<endl;
        int size = edges.size();
        adj.resize(n);
        isVisited.resize(n,false);
        for(int i = 0;i<size;++i) {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        return util(start,end);
    }
};