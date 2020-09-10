class Solution {
public:
    string getHint(string secret, string guess) {
        int size = secret.size();
        unordered_map<char,int> cache;
        int bull=0,cows=0;
        for(int i = 0;i<size;++i) {
            if (secret[i]==guess[i]) {
                ++bull;
            } else {
                ++cache[secret[i]];
            }
        }
        
        for(auto x:guess) {
            if (cache.find(x) != cache.end()) {
                if (cache[x] > 0) {
                    ++cows;
                    --cache[x];
                }
            }
        }
        
        return (to_string(bull)+'A'+to_string(cows)+'B');
     }
};