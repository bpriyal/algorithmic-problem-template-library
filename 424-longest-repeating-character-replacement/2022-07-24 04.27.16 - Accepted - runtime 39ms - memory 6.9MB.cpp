class Solution {
    bool util(const vector<int> &cache, int k) {
        int highestFrequency = 0;
        int sum = 0;
        
        for(int i = 0; i < 26; ++i) {
            if (cache[i] != 0) {
                highestFrequency = max(highestFrequency, cache[i]);
                sum += cache[i];
            }
        }
        
        if (sum - highestFrequency > k) return false;
         
        return true;
    }
public:
    int characterReplacement(string s, int k) {
        int size = s.size();
        int result = k;
        
        vector<int> cache(26, 0);
        
        for(int i = 0; i < k; ++i) ++cache[s[i] - 'A'];
        
        for(int i = k; i < size; ++i) {
            ++cache[s[i] - 'A'];
            
            if (util(cache, k)) ++result;
            else --cache[s[i - result] - 'A'];
        }
        
        return result;
    }
};