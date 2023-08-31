class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        int size1 = sentence1.size();
        int size2 = sentence2.size();
        if (size1 != size2) return false;
        unordered_map<string, string> cache;
        for (const auto& pair : similarPairs) cache.emplace(pair[0], pair[1]);

        for (int i = 0;i < size1; ++i) {
            if (sentence1[i] == sentence2[i]) continue;
            if (sentence1[i] != cache[sentence2[i]] && cache[sentence1[i]] != sentence2[i]) return false;
        }
        return true;
    }
};