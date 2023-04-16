class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int s_size = s.size();
        int t_size = t.size();
        if (s_size != t_size) return false;

        unordered_map<char, char> s_cache;
        unordered_map<char, char> t_cache;

        for (int i = 0; i < s_size; ++i) {
            if (s[i] != t[i]) {
                if (t_cache.find(t[i]) != t_cache.end()) {
                    if (t_cache[t[i]] != s[i]) return false;
                } else {
                    t_cache[t[i]] = s[i];
                }

                if (s_cache.find(s[i]) != s_cache.end()) {
                    if (s_cache[s[i]] != t[i]) return false;
                } else {
                    s_cache[s[i]] = t[i];
                }
            }
        }

        return true;
    }
};