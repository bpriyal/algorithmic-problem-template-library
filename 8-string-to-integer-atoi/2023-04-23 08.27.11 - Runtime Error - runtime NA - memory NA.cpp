class Solution {
    bool checkSign(const string& s, int& currentPos) {
        if (s[currentPos] == '-') {
            ++currentPos;
            return true;
        } else if (s[currentPos] == '+') {
            ++currentPos;
            return false;
        }
        return false;
    }
public:
    int myAtoi(string s) {
        int intRepresentation = 0;
        if (s.empty()) return intRepresentation;
        int size = s.size();
        int currentPos = 0;

        while (currentPos < size && s[currentPos] == ' ') ++currentPos;
        if (currentPos >= size) return intRepresentation;
        
        bool isNegative = checkSign(s, currentPos);
        if (currentPos >= size) return intRepresentation;

        while (currentPos < size && isdigit(s[currentPos])) {
            intRepresentation = intRepresentation * 10 + (s[currentPos] - '0');
            ++currentPos;
        }
        return isNegative? -1 * intRepresentation : intRepresentation;
    }
};
