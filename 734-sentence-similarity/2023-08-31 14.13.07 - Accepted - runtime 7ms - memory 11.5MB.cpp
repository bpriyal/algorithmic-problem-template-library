class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        int size1 = sentence1.size();
        int size2 = sentence2.size();
        if (size1 != size2) return false;
        unordered_map<string, unordered_set<string>> cache;
        for (const auto& pair : similarPairs) {
            cache.try_emplace(pair[0], unordered_set<string>());
            cache[pair[0]].emplace(pair[1]);
        }

        for (int i = 0;i < size1; ++i) {
            if (sentence1[i] == sentence2[i]) continue;
            if (cache[sentence2[i]].count(sentence1[i]) == 0 && cache[sentence1[i]].count(sentence2[i]) == 0) return false;
        }
        return true;
    }
};