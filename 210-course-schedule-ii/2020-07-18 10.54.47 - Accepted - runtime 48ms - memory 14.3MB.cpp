class Solution {
    vector<vector<int>> adj;
    vector<int> result;
    
    bool util(int i,vector<int> &visited) {
        if (visited[i] == 2) return true;;
        if (visited[i] == 1) {
            //cout<<i<<endl;
            return false;
        }
        visited[i] = 1;
        for(auto &x:adj[i]) {
            if (!util(x,visited)) {
                return false;
            }
        }
        visited[i] = 2;
        result.emplace(result.begin(),i);
        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses == 0) return result;
        vector<int> visited(numCourses,0);
        adj.resize(numCourses);
        for(auto &pair:prerequisites) {
            adj[pair[1]].push_back(pair[0]);
        }
        for(int i = 0;i<numCourses;++i) {       
            if (visited[i]==0) {
                if (!util(i,visited)) {
                    //cout<<"here"<<endl;
                    return vector<int>();
                }
            }
        }
        return result;
    }
};