class Solution {
public:
    int minFlips(string target) {
        int size = target.size();
        string s(size,'0');
        int count = 0;
        for(int i = 0;i < size;++i) {
            if (s[i] == target[i]) {
                continue;
            }
            ++count;
            for(int j = i;j < size;++j) {
                if (s[j] == '0') {
                    s[j] = '1';
                } else {
                    s[j] = '0';
                }
            }
        }
        return count;
    }
};