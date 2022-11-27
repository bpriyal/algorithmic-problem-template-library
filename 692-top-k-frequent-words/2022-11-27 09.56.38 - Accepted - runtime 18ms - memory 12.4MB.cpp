class Comp {
public:
    bool operator()(const pair<string, int>& p1, const pair<string, int>& p2) {
        if (p1.second == p2.second) return p1.first < p2.first;
        return p1.second > p2.second;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<string, int>, vector<pair<string, int>>, Comp> pq;
        unordered_map<string, int> cache;
        vector<string> result(k);
        
        for (auto word : words) { // O(n)
            ++cache[word];
        }

        for (auto it = cache.begin(); it != cache.end(); ++it) { // n * logn + (n - k) * logn = logn * (2n - k)
            pq.emplace(it->first, it->second);
            if (pq.size() > k) pq.pop();
        }

        while (!pq.empty()) { // K * logn(n)
            result[--k] = pq.top().first;
            pq.pop();
        }

        return result;
    }
};