class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int size1 = word1.size();
        int size2 = word2.size();
        int w1 = 0, w2 = 0;
        int c1 = 0, c2 = 0;
        
        while (w1 < size1 && w2 < size2) {
            int wsize1 = word1[w1].size();
            int wsize2 = word2[w2].size();
            
            while (c1 < wsize1 && c2 < wsize2) {
                if (word1[w1][c1++] != word2[w2][c2++]) return false;
            }
            
            if (c1 == wsize1) { c1 = 0; w1++; }
            if (c2 == wsize2) { c2 = 0; w2++; }
        }
        
        return w1 == size1 && w2 == size2;
    }
};