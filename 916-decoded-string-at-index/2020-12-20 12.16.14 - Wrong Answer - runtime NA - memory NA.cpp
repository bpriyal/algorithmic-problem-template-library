class Solution {
public:
    string decodeAtIndex(string S, int K) {
        string cache;
        string result = "";
        for(char c:S) {
            if (cache.size() >= K) {
                result += cache[K-1];
                return result;
            }
            if (isalpha(c)) {
                cache.push_back(c);
            } else {
                int n = c - '0' - 1;
                //cout<<n<<endl;
                while(n > 0) {
                    if (cache.size() >= K) {
                        result += cache[K-1];
                        return result;
                    }
                    cache += cache;
                    --n;
                }
                //cout<<cache<<endl;
            }
        }
        result += cache[K-1];
        return result;
    }
};