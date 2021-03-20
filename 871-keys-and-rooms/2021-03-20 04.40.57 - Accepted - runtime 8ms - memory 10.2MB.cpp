class Solution {
    vector<bool> visited;
    int size;
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        size = rooms.size();
        visited.resize(size,false);
        
        stack<int> s;
        s.push(0);
        
        while(!s.empty()) {
            int room = s.top();
            s.pop();
            if (!visited[room]) {
                visited[room] = true;
                for(int n:rooms[room]) {
                    s.push(n);
                }
            }
        }
        
        for(bool isVisited:visited) {
            if (!isVisited) {
                return false;
            }
        }
        return true;
    }
};