class Solution {
public:
    int calculate(string s) {
        if (s.length()==0)
            return 0;
			
        int prevNum=0;
        int currNum=0;
        char prevSign='+';
        int ans=0;
		
        s=getThatOuttaHere(s);
		
        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                currNum=currNum*10+(s[i]-'0'); 
            }
			
            if (!isdigit(s[i])||i==s.length()-1) {
                if (prevSign=='+'){
                    ans=ans+prevNum;
                    prevNum=currNum;
                }
                else if (prevSign=='-') {
                    ans=ans+prevNum;
                    prevNum=-currNum;
                }
				else if (prevSign=='*') 
                    prevNum=prevNum*currNum;
                else if (prevSign=='/')
                    prevNum=prevNum/currNum;
                prevSign=s[i];
                currNum=0;
            }
        }
        ans=ans+prevNum;
        return ans;
    }
    
    string getThatOuttaHere(string inHere) 
    {
        inHere.erase(std::remove(inHere.begin(), inHere.end(), ' '), inHere.end());
        return inHere;
    }
};