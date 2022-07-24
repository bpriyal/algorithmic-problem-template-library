class Solution {
    bool util(const vector<int> &cache, int k) {
        int first = -1;
        int second = -1;
        
        for(int i = 0; i < 26; ++i) {
            if (cache[i] != 0) {
                if (first != -1 && second != -1) return false;
                if (first == -1) first = i;
                else second = i;
            }
        }
        
        return second == -1 || (min(cache[first], cache[second]) <= k);
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
                cout<<i-result<<endl;
                --cache[s[i - result] - 'A'];
            }
        }
        
        return result;
    }
};