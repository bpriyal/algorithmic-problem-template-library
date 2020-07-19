class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int i = a.size()-1;
        int j = b.size()-1;
        int carry = 0;
        while (i >= 0 && j >=0) {
            int x = a[i]-'0';
            //cout<<"x:"<<x<<endl;
            int y = b[j]-'0';
            int res = x+y+carry;
            //cout<<res<<endl;
            if (res == 1) {
                result += '1';
                carry = 0;
                --i;
                --j;
            } else if (res == 2) {
                result += '0';
                carry = 1;
                --i;
                --j;
            } else if (res == 0) {
                result += '0';
                carry = 0;
                --j;
                --i;
            } else if (res == 3) {
                result += '1';
                carry = 1;
                --i;
                --j;
            }
        }
        if (j >= 0) {
            i = j;
            a = b;
        }
        while (i >= 0) {
            int res = a[i]-'0' + carry;
            if (res == 1) {
                result += '1';
                carry = 0;
                --i;
            } else if (res == 0) {
                result += '0';
                carry = 0;
                --i;
            } else if (res == 2) {
                result += '0';
                carry = 1;
                --i;
            }
        }
        if (carry == 1) {
            result += '1';
        }
        reverse(result.begin(),result.end());
        return result;
    }
};