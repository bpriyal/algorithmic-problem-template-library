class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int size = s.size();
        int resultantShift = 0;
        for (const auto& element : shift) {
            resultantShift += element[0]? element[1] : -1 * element[1];
        }

        string prefix, suffix;
        if (resultantShift == 0) return s;
        else if (resultantShift > 0) {
            int shift = size - (abs(resultantShift) % size);
            prefix = s.substr(shift);
            suffix = s.substr(0, shift);
        } else {
            int shift = abs(resultantShift) % size;
            prefix = s.substr(shift);
            suffix = s.substr(0, shift);
        }
        return prefix + suffix;
    }
};