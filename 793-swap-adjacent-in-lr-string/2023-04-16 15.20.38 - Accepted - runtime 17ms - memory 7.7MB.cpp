class Solution {
    unordered_set<char> _cache = {'L', 'R'};
public:
    bool canTransform(string start, string end) {
        int size = start.size();
        string startOrder, endOrder;
        for (auto c : start) if (_cache.count(c)) startOrder += c;
        for (auto c : end) if (_cache.count(c)) endOrder += c;

        if (startOrder != endOrder) return false;

        int p1 = 0, p2 = 0;
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