class Solution {
public:
    int scoreOfParentheses(string S) {
        int size = S.size();
        int balance = 0,result = 0;
        for(int i = 0;i < size;++i) {
            if (S[i] == '(') {
                ++balance;
            } else {
                --balance;
                if (S[i-1] == '(') {
                    result += 1 << balance;
                }
            }
        }
        return result;
    }
};
