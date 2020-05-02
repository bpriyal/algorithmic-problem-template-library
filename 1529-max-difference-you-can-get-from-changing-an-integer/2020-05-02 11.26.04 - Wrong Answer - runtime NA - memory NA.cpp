class Solution {
public:
    int maxDiff(int num) {
        ostringstream s;
        s<<num;
        string str_num = s.str();
        char c;
        for (int i=0;i<str_num.size();++i) {
            if (str_num[i] !='9') {
                c = str_num[i];
                str_num[i] = '9';
                break;
            }
        }
        for (int i=0;i<str_num.size();++i) {
            if ( str_num[i] == c) {
                str_num[i] = '9';
            }
        }
        cout<<str_num<<endl;
        int x =0;
        string str_num2 = s.str();
        if (str_num2[0] != '1') {
            c = str_num2[0];
            x =1;
            str_num2[0] = '1';
        } else {
            for (int i=1;i<str_num2.size();++i) {
                if (str_num2[i] !='0') {
                    c = str_num2[i];
                    str_num2[i] = '0';
                    break;
                }
            }
        } 
        cout<<str_num2<<endl;
        for (int i=0;i<str_num2.size();++i) {
            if (x ==1){
                if ( str_num2[i] == c) {
                    str_num2[i] = '1';
                }
            } else {
                if ( str_num2[i] == c && i!=0) {
                    str_num2[i] = '0';
                }
            }
        }
        cout<<str_num2<<endl;
        return (stoi(str_num) - stoi(str_num2));
    }
};