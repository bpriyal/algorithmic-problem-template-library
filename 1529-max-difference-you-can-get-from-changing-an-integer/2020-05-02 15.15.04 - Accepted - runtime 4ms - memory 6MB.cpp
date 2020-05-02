class Solution {
public:
    int maxDiff(int num) {
        ostringstream s;
        s<<num;
        string str_num = s.str();
        string str_num2 = s.str();
        char c;
        int i,j;
        for (i=0;i<str_num.size();++i) {
            if (str_num[i] !='9') {
                c = str_num[i];
                str_num[i] = '9';
                break;
            }
        }
        for (i=0;i<str_num.size();++i) {
            if ( str_num[i] == c) {
                str_num[i] = '9';
            }
        }
        cout<<str_num<<endl;
        if(str_num2[0] == '1') {
            for (i=1;i<str_num2.size();++i) {
                if (str_num2[i] != '1' && str_num2[i] != '0') {
                    c = str_num2[i];
                    str_num2[i] = '0';
                    break;
                }
            }
            for (j=i+1;j<str_num2.size();++j) {
                if (str_num2[j] == c) {
                    str_num2[j] = '0';
                }
            }
        } else {
            c = str_num2[0];
            str_num2[0] = '1';
            for (i = 1;i<str_num2.size();++i) {
                if(str_num2[i] == c) {
                    str_num2[i] = '1';
                }
            }
        }
        
        
        cout<<str_num2<<endl;
        return (stoi(str_num) - stoi(str_num2));
    }
};