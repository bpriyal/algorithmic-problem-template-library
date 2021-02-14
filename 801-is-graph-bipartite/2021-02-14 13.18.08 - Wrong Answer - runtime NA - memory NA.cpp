class Solution {
    int size;
    vector<int> cache;
    bool dfs(vector<vector<int>>& graph,int pos,int lastColor) {
       // cout<<pos<<endl;
        if (cache[pos] != 0) {
            if (lastColor == cache[pos]) {
                return false;
            } else {
                return true;
            }
        } 
        
        if (cache[pos] == 0) {
            cache[pos] = lastColor == 1? 2:1;    
        }
        
        for(int num:graph[pos]) {
            bool temp = dfs(graph,num,cache[pos]);
            if (!temp) {
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        size = graph.size();
        cache.resize(size,0);
        return dfs(graph,0,1);
    }
};