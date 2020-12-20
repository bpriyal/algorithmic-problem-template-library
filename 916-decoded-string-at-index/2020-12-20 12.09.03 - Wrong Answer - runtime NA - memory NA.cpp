class Solution {
public:
    string decodeAtIndex(string S, int K) {
        string cache;
        for(char c:S) {
            if (cache.size() == K + 1) {
                //cout<<cache[K-1]<<endl;
                string result(1,cache[K-1]);
                return result;
            }
            if (isalpha(c)) {
                cache.push_back(c);
            } else {
                int n = c - '0' - 1;
                while(n > 0) {
                    cache += cache;
                    --n;
                }
            }
        }
        return "";
    }
};