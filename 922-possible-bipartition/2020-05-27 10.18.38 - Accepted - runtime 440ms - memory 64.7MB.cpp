class Solution {
public:
    vector<vector<int>> adjgraph;
    vector<int> visited;
    bool dfs(int index, int color) {
        if (visited[index] == -1) {
            visited[index] = color==0? 1:0;
        } else {
            if (visited[index] == color) return false;
            else return true;
        }
        for (auto &x:adjgraph[index]) {
            bool result;
            cout<<x<<endl;
            result = dfs(x,visited[index]);
            if (!result) return false;
        }
        return true;
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        if (N <= 2) return true;
        adjgraph.resize(N);
        visited.resize(N,-1);
        for (auto &ele:dislikes) {
            adjgraph[ele[0]-1].push_back(ele[1]-1);
            adjgraph[ele[1]-1].push_back(ele[0]-1);
        }
        cout<<"here"<<endl;
        for (int i = 0;i<N;++i) {
            bool result = true;
            if (visited[i] == -1)
                result = dfs(i,0);
            if (!result) return false;
        }
        return true;
    }
};