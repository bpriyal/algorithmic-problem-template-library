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

            cache.[right + 1];
            result = max(result, right - left + 1);
            cout<<"right: "<<right<<", result:"<<result<<endl;
        }

        return result;

        // int n = int(s.length()), res = 0;
        // unordered_map<char, int> mp;

        // for (int j = 0, i = 0; j < n; j++){
        //     if(mp[s[j]] > 0) {
        //         i = max(mp[s[j]], i);
        //     }
        //     res = max(res, j - i + 1);
        //     mp[s[j]] = j + 1;
        // }
        // return res;
    }
};