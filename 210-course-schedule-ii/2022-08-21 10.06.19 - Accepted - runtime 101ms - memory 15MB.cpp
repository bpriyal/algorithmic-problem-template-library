class Solution {
    vector<int> visited;
    vector<int> result;
    
    bool util(const vector<vector<int>>& cache, int row) {
        cout<<"In util for: "<<row<<endl;
        if (visited[row] == 1) {
            cout<<"returning false"<<endl;
            return false;
        }
        if (visited[row] == 2) {
            cout<<"returning true"<<endl;
            return true;
        }
        
        visited[row] = 1;
        
        for (auto it : cache[row]) {
            if (!util(cache, it)) return false;
        }
        visited[row] = 2;
        cout<<"setting visited as 2 for : "<<row<<endl;
        result.push_back(row);
        
        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        visited.resize(numCourses, 0);
        
        vector<vector<int>> cache(numCourses);
        
        for (auto it : prerequisites) {
            cache[it[0]].push_back(it[1]);
        }
        
        for(int i = 0; i < numCourses; ++i) {
            cout<<"starting for: "<<i<<endl;
            if (!util(cache, i)) {
                cout<<i<<endl;
                return {};
            }
        }
        
        return result;
    }
};