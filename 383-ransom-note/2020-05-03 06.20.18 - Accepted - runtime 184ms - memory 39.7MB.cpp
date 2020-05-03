class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.empty()) return true;
        if (magazine.empty()) return false;
        unordered_multiset<char> mag;
        for (auto x : magazine) {
            mag.insert(x);
        }
        for (auto x : ransomNote) {
            unordered_multiset<char>::iterator it = mag.find(x);
            if (it != mag.end()) {
                mag.erase(it);
            } else {
                return false;
            }
        }
        return true;
    }
};