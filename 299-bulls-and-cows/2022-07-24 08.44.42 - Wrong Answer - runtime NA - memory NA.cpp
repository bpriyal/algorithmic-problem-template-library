class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> cache;
        unordered_set<int> indicesToSkip;
        int bulls = 0;
        int cows = 0;
        
        for(int i = 0;i < secret.size(); ++i) {
            if (secret[i] == guess[i]) {
                indicesToSkip.insert(i);
                ++bulls;
            }
            else {
                if (cache.find(secret[i]) != cache.end()) {
                    cache[secret[i]] = 0;
                } else ++cache[secret[i]];
            }
        }
        
        for(int i = 0; i < guess.size(); ++i) {
            if (indicesToSkip.find(i) != indicesToSkip.end()) continue;
            if (cache.find(guess[i]) != cache.end() && cache[guess[i]]-- > 0) ++cows;
        }
        
        string result = "";
        
        result += to_string(bulls) + 'A' + to_string(cows) + 'B';
        
        return result;
    }
};