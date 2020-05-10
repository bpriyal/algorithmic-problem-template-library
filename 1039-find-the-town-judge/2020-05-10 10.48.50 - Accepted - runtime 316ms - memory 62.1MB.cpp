class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        unordered_map<int,pair<int,int>> cache;
        for (int i=1;i<=N;++i) {
            pair<int,int> p;
            p.first = 0;
            p.second = 0;
            cache.insert(make_pair(i,p));
        }
        for(int i=0;i<trust.size();++i) {
            auto it = cache.find(trust[i][0]);
            ++it->second.first;
            it = cache.find(trust[i][1]);
            ++it->second.second;
        }
        for (auto it = cache.begin();it != cache.end();++it) {
            if (it->second.first == 0 && it->second.second == N-1) return it->first;
        }
        return -1;
    }
};