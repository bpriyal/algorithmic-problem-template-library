class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int N = quality.size();
        double result = INT_MAX;
        vector<pair<int, int>> cache;
        priority_queue<int> pq;
        int sumOfQuality = 0;

        for (int i = 0; i < N; ++i) {
            cache.emplace_back(make_pair(wage[i], quality[i]));
        }
        sort(cache.begin(), cache.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return static_cast<double>(a.first)/a.second < static_cast<double>(b.first)/b.second;
        });

        for (const auto& captain : cache) {
            pq.emplace(captain.second);
            sumOfQuality += captain.second;
            if (pq.size() > k) {
                sumOfQuality -= pq.top();
                pq.pop();
            }
            if (pq.size() == k) {
                result = min(result, sumOfQuality * static_cast<double>(captain.first)/captain.second);
            }
        }

        return result;
    }
};