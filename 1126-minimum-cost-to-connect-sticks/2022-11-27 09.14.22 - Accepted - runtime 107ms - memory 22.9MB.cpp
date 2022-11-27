class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> pq(sticks.begin(), sticks.end());
        int result = 0;

        while (pq.size() >= 2) {
            int stick1 = pq.top(); pq.pop();
            int stick2 = pq.top(); pq.pop();

            result += stick1 + stick2;

            pq.emplace(stick1 + stick2);
        }

        return result;
    }
};