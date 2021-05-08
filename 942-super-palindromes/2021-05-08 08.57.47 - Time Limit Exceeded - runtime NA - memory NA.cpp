class Solution {
    bool isPalindrome(string s) {
        //cout<<"isPalindrome"<<s<<endl;
        int size = s.size();
        for(int i = 0,j = size-1;i < j;++i,--j) {
            if (s[i] != s[j]) {
                //cout<<"returning false"<<endl;
                return false;
            }
        }
        //cout<<"returning true"<<endl;
        return true;
    }
public:
    int superpalindromesInRange(string left, string right) {
        int l = atoi(left.c_str());
        int r = atoi(right.c_str());
        
        int result = 0;
        
        for(int i = l;i <= r;++i) {
            //cout<<"In loop"<<endl;
            if (isPalindrome(to_string(i))) {
                //cout<<"2"<<endl;
                double d = sqrt(i);
                if (d-static_cast<int>(d) == 0) {
                    if (isPalindrome(to_string(static_cast<int>(d)))) {
                        ++result;
                    }
                }
            }
        }
        
        return result;
    }
};