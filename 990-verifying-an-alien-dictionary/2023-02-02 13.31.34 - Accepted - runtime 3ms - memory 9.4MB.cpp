class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int size = words.size();
        vector<int> cache(26);
        for (int i = 0; i < 26; ++i) cache[order[i] - 'a'] = i;
        
        for (int i = 0; i < size - 1; ++i) {
            const string& first = words[i];
            int firstSize = first.size();
            const string& second = words[i + 1];
            int secondSize = second.size();

            int j = 0, k = 0;
            while (j < firstSize && k < secondSize) {
                if (cache[first[j] - 'a'] > cache[second[k] - 'a']) return false;
                else if (cache[first[j] - 'a'] < cache[second[k] - 'a']) break;
                ++j;
                ++k;
            }
            if (j != firstSize && k == secondSize) return false;
        }
        return true;
    }
};