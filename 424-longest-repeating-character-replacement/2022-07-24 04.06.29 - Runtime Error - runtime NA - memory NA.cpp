class Solution {
    bool util(const vector<int> &cache, int k) {
        std::optional<int> first;
        std::optional<int> second;
        
        for(int i = 0; i < 26; ++i) {
            if (cache[i] != 0) {
                if (first && second) return false;
                if (!first) *first = i;
                else *second = i;
            }
        }
        
        return min(cache[*first], cache[*second]) <= k;
    }
public:
    int characterReplacement(string s, int k) {
        int size = s.size();
        int result = k;
        
        vector<int> cache(26, 0);
        
        for(int i = 0; i < k; ++i) ++cache[s[i] - 'A'];
        
        for(int i = k; i < size; ++i) {
            ++cache[s[i] - 'A'];
            
            if (util(cache, k)) {
                ++result;
            }
            else {
                --cache[s[i - result] - 'A'];
            }
        }
        
        return result;
    }
};