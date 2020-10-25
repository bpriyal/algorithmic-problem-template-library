class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        int j = tokens.size();
        sort(tokens.begin(),tokens.end());
        int i = 0;
        int result = 0,run = 0;
        while(i < j) {
            if (P >= tokens[i]) {
                ++run;
                P -= tokens[i];
                ++i;
            } else if (run > 0) {
                --run;
                P += tokens[j-1];
                --j;
            } else {
                break;
            }
            result = max(result,run);
        }
        return result;
    }
};