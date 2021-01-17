class Solution {
    int size;
    int count(int n,int lastChar) {
        if (n == 1) {
            return 1;
        }
        int result = 0;
        for(int i = lastChar;i < 5;++i) {
            result += count(n-1,i);
        }
        return result;
    }
public:
    int countVowelStrings(int n) {
       return count(n+1,0); 
    }
};