class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int sizePattern = pattern.size();
        vector<string> result;
        
        for(const string &word:words) {
            if (word.size() != sizePattern) {
                continue;
            }
            unordered_map<char,char> cache;
            unordered_set<char> cs;
            int i;
            for(i = 0;i < sizePattern;++i) {
                if (cache.find(pattern[i]) != cache.end()) {
                    if (word[i] != cache[pattern[i]]) {
                        break;
                    }
                } else {
                    if (cs.find(word[i]) != cs.end()) {
                        break;
                    }
                    cs.insert(word[i]);
                    cache[pattern[i]] = word[i];
                    
                }
            }
            if (i == sizePattern) {
                result.push_back(word);
            }
        }
        
        return result;
    }
};