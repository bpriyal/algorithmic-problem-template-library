class Solution {
    static const int _numberOfChars = 26;
public:
    int calculateTime(string keyboard, string word) {
        unordered_map<char, int> cache;
        for (int i = 0; i < _numberOfChars; ++i) cache.emplace(keyboard[i], i);
        int time = 0;
        int prevPos = 0;
        for (auto c : word) {
            int currentPos = cache[c];
            time += abs(currentPos - prevPos);
            prevPos = currentPos;
        }
        return time;
    }
};