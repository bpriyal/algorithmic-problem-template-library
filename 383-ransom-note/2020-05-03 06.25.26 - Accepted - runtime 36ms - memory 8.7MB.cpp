class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.empty()) return true;
        if (magazine.empty()) return false;
        vector<int> v(26,0); 
        for (auto x : magazine) {
            ++v[x-'a'];
        }
        for (auto x : ransomNote) {
            
            if (v[x-'a'] != 0) {
                --v[x-'a'];
            } else {
                return false;
            }
        }
        return true;
    }
};