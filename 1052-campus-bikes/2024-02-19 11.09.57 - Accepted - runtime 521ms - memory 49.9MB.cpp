// using std::pair<vector<int>, vector<int>> = vectorPair;
// class Compare {
// public:
//     bool operator()(const vector<int>& a, const vector<int> b){
//         if(cond){
//                return true;
//         }
//         return false;
//     }
// };
class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int n = workers.size();
        int m = bikes.size();
        vector<int> result(n, -1);
        unordered_set<int> usedBikes;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int dist = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
                pq.emplace(dist, i, j);
            }
        }
        while (!pq.empty()) {
            const auto [dist, workerIdx, bikeIdx] = pq.top();
            // cout<<dist<<","<<workerIdx<<","<<bikeIdx<<endl;
            pq.pop();
            if (result[workerIdx] == -1 && !usedBikes.count(bikeIdx)) {
                cout<<dist<<",,"<<workerIdx<<",,"<<bikeIdx<<endl;
                // cout<<"in"<<endl;
                result[workerIdx] = bikeIdx;
                usedBikes.emplace(bikeIdx);
            }
        }
        return result;
    }
};