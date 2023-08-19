class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int sizeS = s.size();
        int sizeT = t.size();
        if (s == t || abs(sizeS - sizeT) > 1) return false;
        bool canDelete = (sizeS - sizeT) == 1;
        bool canInsert = (sizeT - sizeS) == 1;
        int i = 0, j = 0;
        bool lifeUsed = false;
        while (i < sizeS && j < sizeT) {
            if (s[i] == t[j]) {
                ++i;
                ++j;
                continue;
            }
            if (!lifeUsed) {
                lifeUsed = true;
                if (canDelete) ++i;
                else if (canInsert) ++j;
                else {
                    ++i;
                    ++j;
                }
            } else return false;
        }
        return (i == sizeS && j == sizeT) || !lifeUsed;
    }
};