class Solution {
    int util(const vector<vector<int>>& adjList_, vector<int>& visited_, int pos) {
        if (visited_[pos] == -1) return -1;
        if (visited_[pos] == 1) return 0;
        visited_[pos] = -1;
        int maxHeight = 0;
        for (auto node : adjList_[pos]) {
            int currHeight = util(adjList_, visited_, node);
            if (currHeight == -1) return -1;
            maxHeight = max(maxHeight, currHeight);
        }
        visited_[pos] = 1;
        return maxHeight + 1;
    }
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<vector<int>> adjList(n);
        vector<int> visited(n, false);
        vector<bool> canLearn(n, true);
        for (const auto& relation : relations) {
            adjList[relation[0] - 1].emplace_back(relation[1] - 1);
            canLearn[relation[1] - 1] = false;
        }
        int result = 0;
        for (int i = 0; i < n; ++i) {
            if (visited[i] == 0 && canLearn[i]) {
                int temp = util(adjList, visited, i);
                if (temp == -1) return -1;
                result = max(result, temp);
            }
        }
        return result;
    }
};