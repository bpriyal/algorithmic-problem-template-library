class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> cache(n+1,false);
        for(int i = 1;i<=n;++i) {
            for(int j = 1;j*j<=i;++j) {
                if (!cache[i-j*j]) {
                    cache[i] = true;
                    break;
                }
            }
        }
        return cache[n];
    }
};