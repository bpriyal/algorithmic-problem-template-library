class Solution {
public:
    bool checkIfPangram(string sentence) {
        int size = sentence.size();
        if (size < 26) return false;
        
        vector<bool> cache(26, false);
        
        for (char c : sentence) cache[c - 'a'] = true;
        
        for (int i = 0; i < 26; ++i) if (!cache[i]) return false;
        
        return true;
    }
};