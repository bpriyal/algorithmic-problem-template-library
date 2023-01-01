class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int size = s.size();
        int numberDash = 0;
        string result = "";

        for (char c : s) if (c == '-') ++numberDash;

        int validCharacters = size - numberDash;

        if (!validCharacters) return "";

        int groups = validCharacters / k;
        int remainder = validCharacters % k;
        int pos = 0;
        
        if (remainder) {
            while (remainder) {
                while (s[pos] == '-') {
                    ++pos;
                }
                result += toupper(s[pos++]);
                --remainder;
            }

            result += '-';
        }

        for (int i = 0; i < groups; ++i) {
            for (int j = 0; j < k; ++j) {
                while (s[pos] == '-') {
                    ++pos;
                }
                result += toupper(s[pos++]);
            }
            result += '-';
        }
        result.pop_back();
        return result;
    }
};