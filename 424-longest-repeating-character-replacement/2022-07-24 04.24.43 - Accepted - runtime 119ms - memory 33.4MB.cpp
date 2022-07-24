class Solution {
    bool util(const vector<int> &cache, int k) {
        vector<int> indices;
        int maxx = 0;
        int sum = 0;
        
        for(int i = 0; i < 26; ++i) {
            if (cache[i] != 0) {
                indices.push_back(i);
                maxx = max(maxx, cache[i]);
                sum += cache[i];
            }
        }
        
        if (indices.size() > k + 1 || sum - maxx > k) return false;
        
        
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
            
            if (util(cache, k)) {
                ++result;
            }
            else {
                //cout<<i-result<<endl;
                --cache[s[i - result] - 'A'];
            }
        }
        
        return result;
    }
};