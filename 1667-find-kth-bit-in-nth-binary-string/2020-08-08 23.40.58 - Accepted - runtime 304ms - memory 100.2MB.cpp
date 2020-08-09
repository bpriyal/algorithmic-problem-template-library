class Solution {
    string revinv(string s) {
        int size = s.size();
        for(int i=0;i<size;++i) {
            s[i] = (s[i] == '0') ? '1':'0';
        }
        for(int i = 0;i<=size/2;++i) {
            swap(s[i],s[size-1-i]);
        }
        return s;
    }
public:
    char findKthBit(int n, int k) {
        string s1 = "0";
        if (n == 1) return '0';
        string temp;
        for(int i = 2;i<=n;++i) {
            temp = s1+"1"+revinv(s1);
            s1 = temp;
        }
        return temp[k-1];
    }
};