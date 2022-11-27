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
        
        for (auto word : words) {
            ++cache[word];
        }

        for (auto it = cache.begin(); it != cache.end(); ++it) {
            pq.emplace(it->first, it->second);
            if (pq.size() > k) pq.pop();
        }

        while (!pq.empty()) {
            result[--k] = pq.top().first;
            pq.pop();
        }

        return result;
    }
};