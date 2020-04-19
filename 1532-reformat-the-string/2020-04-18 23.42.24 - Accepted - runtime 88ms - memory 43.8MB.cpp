class Solution {
public:
    string reformat(string s) {
        if (s == "") return "";
        int i;
        string num;
        string alpha;
        for (i=0;i<s.size();++i) {
            if(isalpha(s[i])) {
                alpha = alpha+s[i];
            } else {
                num =num + s[i];
            }
        }
        char alphanum[num.size()+alpha.size()+1];
        if (num.size() == alpha.size()+1 || num.size() == alpha.size()){
            int i=0,j=0,count=0;
            while(i!=alpha.size()){
                alphanum[count++]=num[j++];
                alphanum[count++]=alpha[i++];
            }
            if (j == num.size()-1) {
                alphanum[count++] =num[j];
            }
            alphanum[count] ='\0';
            return alphanum;
        } 
        if (alpha.size() ==num.size()+1 || alpha.size() == num.size()){
            int i=0,j=0,count=0;
            while(j!=num.size()){
                alphanum[count++]=alpha[i++];
                alphanum[count++]=num[j++];
            }
            if (i == alpha.size()-1) {
                alphanum[count++] =alpha[i];
            }
            alphanum[count] ='\0';
            return alphanum;
        }
        return "";
        
    }
};