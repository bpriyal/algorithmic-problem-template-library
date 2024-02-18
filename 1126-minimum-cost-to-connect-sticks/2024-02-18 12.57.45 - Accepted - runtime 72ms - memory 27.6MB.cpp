class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        int size = sticks.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for (const auto& stick : sticks) pq.emplace(stick);
        int cost = 0;
        while (pq.size() > 1) {
            int least = pq.top(); pq.pop();
            int less = pq.top(); pq.pop();
            // cout<<least<<", "<<less<<endl;
            cost += least + less;
            pq.emplace(least + less);
        }
        return cost;
    }
};