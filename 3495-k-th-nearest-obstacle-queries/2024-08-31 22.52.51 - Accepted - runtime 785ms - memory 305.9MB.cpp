class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        auto cmp = [](const vector<int>& v1, const vector<int>& v2) {
          return (abs(v1[0]) + abs(v1[1])) < (abs(v2[0]) + abs(v2[1]));
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq;

        vector<int> result;
        for (const auto& query : queries) {
          if (pq.size() < k) pq.emplace(query);
          else {
            const auto& top = pq.top();
            if (abs(top[0]) + abs(top[1]) > abs(query[0]) + abs(query[1])) {
              pq.pop();
              pq.emplace(query);
            }
          }
          if (pq.size() < k) result.emplace_back(-1);
          else {
            const auto& top = pq.top();
            result.emplace_back(abs(top[0]) + abs(top[1]));
          }
        }
        return result;
    }
};