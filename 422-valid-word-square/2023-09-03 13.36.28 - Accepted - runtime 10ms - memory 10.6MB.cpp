class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int rows = words.size();
        int cols = words[0].size();
        if (rows != cols) return false;
        int k = max(rows, cols);
        for (int i = 0; i < k; ++i) {
            string kColStr;
            for (int j = 0; j < rows; ++j) {
                if (i >= words[j].size()) break;
                kColStr += words[j][i];
            }
            if (kColStr != words[i]) return false;
        }
        return true;
    }
};