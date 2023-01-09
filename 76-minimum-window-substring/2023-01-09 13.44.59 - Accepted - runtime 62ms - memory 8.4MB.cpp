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
            //cout<<"right: "<<right<<endl;
            while (left < m) {
                //cout<<"left: "<<left<<endl;
                if (charCache.find(s[left]) != charCache.end()) {
                    if (cache[s[left]] > 0) {
                        --cache[s[left]];
                        //if (cache[s[left]] < 0) {
                            //cout<<"removing: "<<s[left]<<", map: "<<runningCharCache[s[left]]<<endl;
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
            if (resultSize > right - left + 1) {
                bool correct = true;
                for (char c : t) {
                    if (runningCharCache[c] < charCache[c]) {
                        correct = false;
                        break;
                    }
                }
                if (correct) {
                    //cout<<"here1"<<endl;
                    resultSize = right - left + 1;
                    result = {left, right};
                }
            }
        }
        //cout<<"first: "<<result.first<<"second: "<<result.second<<endl;
        if (result.first == -1 || result.second == -1) return "";
        return s.substr(result.first, result.second - result.first + 1);
    }
};