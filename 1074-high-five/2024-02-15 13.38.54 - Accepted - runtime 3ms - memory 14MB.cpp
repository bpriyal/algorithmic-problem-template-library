class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int, std::priority_queue<int, vector<int>, greater<int>>> cache;
        vector<vector<int>> result;
        for (const auto& item : items) {
            if (cache.contains(item[0])) {
                auto& pq = cache[item[0]];
                if (pq.size() < 5) pq.emplace(item[1]);
                else if (auto top = pq.top(); top < item[1]) {
                    pq.pop();
                    pq.emplace(item[1]);
                }
            } else {
                // cout<<item[0]<<endl;
                cache[item[0]].emplace(item[1]);
            }
        }

        for (auto& [id, pq] : cache) {
            cout<<id<<endl;
            int sum = 0;
            while (!pq.empty()) {
                sum += pq.top();
                pq.pop();
            }
            result.emplace_back(vector<int>{id, sum / 5});
        }
        return result;
    }
};