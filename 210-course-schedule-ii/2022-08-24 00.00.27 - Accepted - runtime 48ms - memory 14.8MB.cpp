class Solution {
    vector<int> visited;
    vector<int> result;
    
    bool util(const vector<vector<int>>& cache, int row) {
        if (visited[row] == 1) return false;
        if (visited[row] == 2) return true;
        
        visited[row] = 1;
        
        for (auto it : cache[row]) {
            if (!util(cache, it)) return false;
        }
        
        visited[row] = 2;
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
            if (!util(cache, i)) return {};
        }
        
        return result;
    }
};