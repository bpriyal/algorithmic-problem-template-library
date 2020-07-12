class Solution {
public:
    int numSub(string s) {
        int size = s.size();
        int i,j,count = 0;
        int mod = 1000000007;
        vector<int> cache(100001);
        cache[0] = 0;
        cache[1] = 1;
        for(int i=2;i<100001;++i) {
            cache[i] = (cache[i-1]%mod + i)%mod;
        }
        i = j = 0;
        while (i<size) {
            if (s[i] == '1') {
                while(j<size && s[j] == '1') {
                    ++j;
                }
                count += cache[j-i]%mod;
                ++j;
                i = j;
            } else {
                ++i;
                ++j;
            }
        }
        return count;
    }
};