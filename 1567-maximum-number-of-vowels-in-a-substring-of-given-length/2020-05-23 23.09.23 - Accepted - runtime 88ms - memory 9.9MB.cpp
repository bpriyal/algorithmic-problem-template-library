class Solution {
public:
    int maxVowels(string s, int k) {
        int size = s.size();
        int count = 0;
        int maxsofar;
        for (int i = 0;i < k;++i) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                ++count;
            }
        }
        maxsofar = count;
        for (int i = k;i < size;++i) {
            if (s[i-k] == 'a' || s[i-k] == 'e' || s[i-k] == 'i' || s[i-k] == 'o' || s[i-k] == 'u') {
                --count;
            }
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                ++count;
            }
            maxsofar = max(maxsofar,count);
        }
        return maxsofar;
    }
};