class Solution {
    public:
    string sup;
    int longestSubstring(string s, int k) {
        int n = s.length();
        if (k>n)
            return 0;
        else if (k==1)
            return n;
        sup=s;
        return splitInTwo(k, 0, n);
    }
    int splitInTwo(int k, int beg, int end) {
        if (end-beg < k) return 0;
        int bets[26] = {0};
        for (int i = beg; i < end; i++)
            bets[sup[i] - 97]++;
        for (int i = beg; i < end; i++) {
            if (bets[sup[i] - 97] < k){
                int next = i + 1;
                while (next < end && bets[sup[next] - 97] < k) 
                    next++;
                return max(splitInTwo(k, beg, i), splitInTwo(k, next, end));
            } 
            
        }
        return (end - beg);
    }
};