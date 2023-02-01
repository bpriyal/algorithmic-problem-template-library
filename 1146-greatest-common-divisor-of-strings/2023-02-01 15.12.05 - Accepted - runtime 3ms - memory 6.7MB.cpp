class Solution {
    bool checkValidity(const string& str, const string& gcd) {
        int gcdSize = gcd.size();
        int strSize = str.size();
        if (strSize % gcdSize != 0) return false;  
        for (int i = 0, j = 0; i < strSize; ++i, ++j) {
            if (j % gcdSize == 0) j = 0;
            if (str[i] != gcd[j]) return false;
        }
        return true;
    }
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1.size() < str2.size()) swap(str1, str2);
        int size1 = str1.size();
        int size2 = str2.size();

        string gcd = str2;
        while (!gcd.empty()) {
            if (!checkValidity(str2, gcd) || !checkValidity(str1, gcd)) {
                do {
                    gcd.pop_back();
                } while (gcd.size() && size2 % gcd.size() != 0);
            } else {
                return gcd;
            }
        }
        return gcd;
    }
};