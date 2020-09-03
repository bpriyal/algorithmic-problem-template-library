class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int size = s.size();
        //cout<<size<<endl;
        if (size <= 1) {
            return false;
        }
        string sub = "";
        for(int i = 0;i<size/2;++i) {
            sub += s[i];
            //cout<<sub<<endl;
            int subSize = sub.size();
            if ((size-subSize)%subSize == 0) {
                int j = subSize;
                while(j+subSize <= size) {
                    if (sub != s.substr(j,subSize)) {
                        break;
                    }
                    j += subSize;
                }
                //cout<<j+subSize<<endl;
                if (j == size) {
                    return true;
                }
            }
        }
        return false;
    }
};