class Comp {
public:
    Comp() {}
    ~Comp() {}
    
    bool operator()(const pair<string,int> &a, const pair<string,int> &b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second > b.second;
    }
};

typedef priority_queue<pair<string, int>, vector<pair<string, int>>, Comp> PQ;

class Solution {   
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> frequency;
        
        for(const auto &word : words) {
            if (frequency.find(word) == frequency.end()) frequency[word] = 0;
            else ++frequency[word];
        }
        
        PQ pq;

        for(auto it = frequency.begin(); it != frequency.end(); ++it) {
            pq.emplace(it->first, it->second);
            if (pq.size() > k) pq.pop();
        }
        
        vector<string> result;
        
        while(!pq.empty()) {
            result.push_back(pq.top().first);
            pq.pop();
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};