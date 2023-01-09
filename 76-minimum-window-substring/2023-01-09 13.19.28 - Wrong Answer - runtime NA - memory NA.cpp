class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        int left = 0, right = 0;
        unordered_map<char, int> cache;
        unordered_map<char, int> charCache;
        unordered_map<char, int> runningCharCache;
        pair<int, int> result = { -1, -1 };
        int resultSize = INT_MAX;

        for (auto c : t) --cache[c];
        for (auto c : t) ++charCache[c];

        for (right = 0; right < m; ++right) {
            if (charCache.find(s[right]) != charCache.end()) ++runningCharCache[s[right]];
            ++cache[s[right]];
            cout<<"right: "<<right<<endl;
            while (left < m) {
                cout<<"left: "<<left<<endl;
                if (charCache.find(s[left]) != charCache.end()) {
                    if (cache[s[left]] > 0) {
                        --cache[s[left]];
                        //if (cache[s[left]] < 0) {
                            cout<<"removing: "<<s[left]<<", map: "<<runningCharCache[s[left]]<<endl;
                            --runningCharCache[s[left]];
                            if (runningCharCache[s[left]] == 0) runningCharCache.erase(s[left]);
                        //}
                        ++left;
                    } else break;
                } else {
                    --cache[s[left]];
                    ++left;
                }
            }

            if (right == 0 && left == 0) {
                if (runningCharCache == charCache) cout<<"match"<<endl;
                else cout<<"Do not"<<endl;

                for (auto it : runningCharCache) {
                    cout<<"key: "<<it.first<<", value: "<<it.second<<endl;
                }
            }
            if (runningCharCache == charCache && resultSize > right - left + 1) {
                cout<<"here1"<<endl;
                resultSize = right - left + 1;
                result = {left, right};
            }
        }
        
        if (result.first == -1 || result.second == -1) return "";
        return s.substr(result.first, result.second + 1);
    }
};