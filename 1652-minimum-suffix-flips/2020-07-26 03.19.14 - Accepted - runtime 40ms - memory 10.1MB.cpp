class Solution {
public:
    int minFlips(string target) {
        int size = target.size();
        string s(size,'0');
        int count = 0;
        char status = '0';
        for(int i = 0;i < size;++i) {
            if (status == target[i]) {
                continue;
            }
            ++count;
            if (status == '0') {
                status = '1';
            } else {
                status = '0';
            }
        }
        return count;
    }
};