class Solution {
public:
    bool detectCapitalUse(string word) {
        int size = word.size();
        if (size <= 1) return true;
        if (word[0] >='A' && word[0] <= 'Z') {
            if (word[1] >= 'A' && word[1] <= 'Z') {
                for(int i = 2;i<size;++i) {
                    if (!(word[i] >='A' && word[i] <= 'Z')) {
                        return false;
                    }
                }
                return true;
            } else {
                for(int i = 2;i<size;++i) {
                    if (word[i] >='A' && word[i] <= 'Z') {
                        return false;
                    }
                }
                return true;
            }
        } else {
            for(int i = 1;i<size;++i) {
                if (word[i] >='A' && word[i] <= 'Z') {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
};