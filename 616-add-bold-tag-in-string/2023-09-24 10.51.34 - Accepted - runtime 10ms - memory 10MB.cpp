class Solution {
public:
    string addBoldTag(string s, vector<string>& words) {
        int size = s.size();
        vector<bool> bold(size, false);
        for (const auto& word : words) {
            int lastLoc = s.find(word);
            while (lastLoc != -1) {
                for (int i = lastLoc; i < lastLoc + word.size(); ++i) bold[i] = true;
                lastLoc = s.find(word, lastLoc + 1);
            }
        }
        string startTag = "<b>";
        string closeTag = "</b>";
        string result;
        for (int i = 0; i < size; ++i) {
            if (bold[i] && (i == 0 || !bold[i-1])) result += startTag;
            result += s[i];
            if (bold[i] && (i == size - 1 || !bold[i+1])) result += closeTag;
        }
        return result;
    }
};