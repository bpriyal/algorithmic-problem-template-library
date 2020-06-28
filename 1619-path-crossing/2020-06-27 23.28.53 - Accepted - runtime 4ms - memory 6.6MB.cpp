class Solution {
public:
    bool isPathCrossing(string path) {
        pair<int,int> p;
        p.first = p.second = 0;
        set<pair<int,int>> cache;
        cache.insert(p);
        for(int i = 0;i<path.size();++i) {
            if (path[i] == 'N') {
                ++p.second;
                auto pos = cache.find(p);
                if (pos != cache.end()) return true;
                cache.insert(p);
            } else if (path[i] == 'S') {
                --p.second;
                auto pos = cache.find(p);
                if (pos != cache.end()) return true;
                cache.insert(p);
            } else if (path[i] == 'W') {
                --p.first;
                auto pos = cache.find(p);
                if (pos != cache.end()) return true;
                cache.insert(p);
            } else if (path[i] == 'E') {
                ++p.first;
                auto pos = cache.find(p);
                if (pos != cache.end()) return true;
                cache.insert(p);
            }
        }
        return false;
    }
};