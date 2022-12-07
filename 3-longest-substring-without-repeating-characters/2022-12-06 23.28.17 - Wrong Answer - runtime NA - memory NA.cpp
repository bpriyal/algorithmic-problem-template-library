class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        int result = 0;
        int left = 0;
        int right = 0;

        unordered_map<char, int> cache;

        for (right = 0; right < size; ++right) {
            char c = s[right];

            if (cache.find(c) != cache.end()) {
                left = max(left, cache[c]);
            }

            cache.emplace(c, right + 1);
            result = max(result, right - left + 1);
            cout<<"right: "<<right<<", result:"<<result<<endl;
        }

        return result;
    }
};