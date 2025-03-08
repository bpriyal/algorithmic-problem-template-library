class Solution {
    int getNumber(const string& abbr, int& startIdx, int abbrSize) {
        int n = 0;
        while (startIdx < abbrSize) {
            // cout << "aakashyap: " << abbr[startIdx] << endl;
            if (isalpha(abbr[startIdx])) return n;
            n = n * 10 + (abbr[startIdx++] - '0');
            // cout << "iter: " << n << endl;
        }
        return n;
    }
public:
    bool validWordAbbreviation(string word, string abbr) {
        int wordSize = word.size();
        int abbrSize = abbr.size();
        int wordIdx = 0;
        int abbrIdx = 0;

        while (abbrIdx != abbrSize) {
            if (isalpha(abbr[abbrIdx])) {
                if (abbr[abbrIdx] != word[wordIdx]) {
                    cout << "return from 1 " << abbr[abbrIdx] << ", " << word[wordIdx];
                    return false;
                }
                ++abbrIdx;
                ++wordIdx;
            } else {
                if (abbr[abbrIdx] == '0') return false; // leading zeros are not allowed
                auto n = getNumber(abbr, abbrIdx, abbrSize);
                cout << n << endl;
                if (wordSize - wordIdx < n) {
                    cout << "return from 1" << endl;
                    return false;
                }
                wordIdx += n;
            }
        }
        return true;
    }
};