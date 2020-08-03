class Solution {
public:
    bool isPalindrome(string s) {
        string temp= "";
        for(auto c:s) {
            if (isalnum(c)) {
                if (c < 'a' && c >= 'A') {
                    temp += c + 'a'-'A';
                } else {
                    temp += c;
                }
            }
        }
        int size = temp.size();
        //cout<<temp<<endl;
        for(int i=0;i<size/2;++i) {
            //cout<<temp[i]<<"\t"<<temp[size-i-1]<<endl;
            if (temp[i] != temp[size-i-1]) {
                return false;
            }
        }
        return true;
    }
};