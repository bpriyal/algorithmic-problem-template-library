class Solution {
    int id;
    unordered_map<string,string> cache;
public:
    Solution() {
        id = 1000;
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shortUrl = "";
        
        int temp = id;
        while(temp && shortUrl.size() < 7) {
            shortUrl += temp%62 + '0';
            temp /= 62;
        }
        
        cache[shortUrl] = longUrl;
        ++id;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        if (cache.find(shortUrl) != cache.end()) {
            return cache[shortUrl];
        } 
        return "";
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));