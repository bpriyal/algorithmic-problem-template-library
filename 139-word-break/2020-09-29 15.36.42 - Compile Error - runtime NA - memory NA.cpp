class Solution {
    bool util(string& s, const unordered_set<string>& words,
                    unordered_map<string, bool>& cache) {
        int n = s.size();
        if (n == 0)
            return true;
        
        if (cache.find(s) != cache.end())
            return cache[s];
        
        for (int i = 1; i <= n; ++i) {
            if (words.find(s.substr(0, i)) != words.end()) {
                if (util(s.substr(i), words, cache)) {
                    cache[s] = true;
                    return true;
                }
                    
            }
        }
        cache[s] = false;
        return false;
    }
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(begin(wordDict), end(wordDict));
        unordered_map<string, bool> cache;
        return util(move(s), words, cache);
    }
};