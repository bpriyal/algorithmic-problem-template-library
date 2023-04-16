class Solution {
    unordered_set<char> _cache = {'L', 'R'};
public:
    bool canTransform(string start, string end) {
        int size = start.size();
        string startOrder, endOrder;
        for (auto c : start) if (_cache.count(c)) startOrder += c;
        for (auto c : end) if (_cache.count(c)) endOrder += c;

        if (startOrder != endOrder) return false;
        return true;
    }
};