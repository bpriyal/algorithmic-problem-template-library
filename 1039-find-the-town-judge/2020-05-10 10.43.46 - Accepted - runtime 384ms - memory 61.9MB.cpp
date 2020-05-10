class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        unordered_map<int,pair<int,int>> cache;
        int i;
        for (int i=1;i<=N;++i) {
            pair<int,int> p;
            p.first = 0;
            p.second = 0;
            cache[i] = p;
        }
        for(auto& x: trust) {
            auto it = cache.find(x[0]);
            ++it->second.first;
            it = cache.find(x[1]);
            ++it->second.second;
        }
        for (auto it = cache.begin();it != cache.end();++it) {
            if (it->second.first == 0 && it->second.second == N-1) return it->first;
        }
        return -1;
    }
};