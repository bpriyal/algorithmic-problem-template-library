class Solution {
public:
    string decodeAtIndex(string S, int K) {
        string cache;
        string result = "";
        for(char c:S) {
            if (cache.size() >= K) {
                //printf("%d,%s\n",1,cache.c_str());
                result += cache[K-1];
                return result;
            }
            if (isalpha(c)) {
                cache.push_back(c);
            } else {
                int n = c - '0' - 1;
                //cout<<n<<endl;
                string temp = cache;
                while(n > 0) {
                    if (cache.size() >= K) {
                        //printf("%d,%s\n",2,cache.c_str());
                        result += cache[K-1];
                        return result;
                    }
                    cache += temp;
                    --n;
                }
                //cout<<cache<<endl;
            }
        }
        //printf("%d,%s\n",3,cache.c_str());
        result += cache[K-1];
        return result;
    }
};