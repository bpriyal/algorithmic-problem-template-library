class Solution {
public:
    bool canTransform(string start, string end) {
        int size = start.size();
        int p1 = 0, p2 = 0;
        string sComp, eComp;
        for (int i = 0; i < size; ++i) {
            if (start[i] != 'X') sComp += start[i];
            if (end[i] != 'X') eComp += end[i];
        }

        if (sComp != eComp) return false;

        while (p1 < size && p2 < size) {
            while (p1 < size && start[p1] == 'X') {
                ++p1;
            }
            while (p2 < size && end[p2] == 'X') {
                ++p2;
            }
            if (p1 == size && p2 == size) return true;
            if (p1 == size || p2 == size) return false;
            if (start[p1] != end[p2]) return false;
            if (start[p1] == 'L' && p1 < p2) return false;
            if (start[p1] == 'R' && p1 > p2) return false;
            ++p1, ++p2;
        }

        return true;
    }
};