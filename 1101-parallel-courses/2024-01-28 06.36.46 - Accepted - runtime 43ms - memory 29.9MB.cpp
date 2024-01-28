class Solution {
    int util(const vector<vector<int>>& adjList_, vector<int>& visited_, int pos) {
        if (visited_[pos] != 0) return visited_[pos];
        visited_[pos] = -1;
        int maxHeight = 1;
        for (auto node : adjList_[pos]) {
            int currHeight = util(adjList_, visited_, node);
            if (currHeight == -1) return -1;
            maxHeight = max(maxHeight, currHeight + 1);
        }
        visited_[pos] = maxHeight;
        return maxHeight;
    }
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<vector<int>> adjList(n);
        vector<int> visited(n, false);
        for (const auto& relation : relations) {
            adjList[relation[0] - 1].emplace_back(relation[1] - 1);
        }
        int result = 0;
        for (int i = 0; i < n; ++i) {
            if (visited[i] == 0) {
                int temp = util(adjList, visited, i);
                if (temp == -1) return -1;
                result = max(result, temp);
            }
        }
        return result;
    }
};