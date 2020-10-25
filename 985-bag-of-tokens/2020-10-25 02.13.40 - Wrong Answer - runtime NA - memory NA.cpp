class Solution {
    int size;
    int util(vector<int>& tokens,int P,int pos,int score) {
        if (pos >= size) {
            return score;
        }
        int temp;
        if (P >= tokens[pos]) {
            return util(tokens,P-tokens[pos],pos+1,score+1);
        } else {
            for(int i = size - 1;i>=pos;--i) {
                if (tokens[i] != -1) {
                    temp = tokens[i];
                    tokens[i] = -1;
                    int a = util(tokens,P+temp,pos+1,score-1);
                    tokens[i] = temp;
                    int b = util(tokens,P,pos+1,score);
                    return max(a,b);
                }
            }
        }
        return -1;
    }
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        size = tokens.size();
        sort(tokens.begin(),tokens.end());
        return util(tokens,P,0,0);
    }
};