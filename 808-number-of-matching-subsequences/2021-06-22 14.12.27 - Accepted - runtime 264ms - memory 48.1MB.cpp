class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char, vector<int>> mp;
        for (int i = 0; i < s.length(); i++) 
        {
            mp[s[i]].push_back(i);
        }
        int numSubseq = 0;
        int low;
        bool isSubseq;
        for (string& word: words) 
        {
            low = -1;
            isSubseq = true;
            for (char& ch : word) 
            {                
                int pos = upper_bound(mp[ch].begin(), mp[ch].end(), low) - mp[ch].begin();
                if (pos == mp[ch].size()) 
                {
                    isSubseq = false;
                    break;
                }
                low = mp[ch][pos];
            }
            numSubseq += isSubseq;
        }
        return numSubseq;
    }
};