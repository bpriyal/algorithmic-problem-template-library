class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int size = sentence.size();
        int search_size = searchWord.size();
        if (search_size > size) return -1;
        int i =0;
        int flag = false;
        int spaces =0;
        for (int k = 0;k<size;++k) {
            if (sentence[k] == ' ') {
                ++spaces;
            }
            if (sentence[k] == searchWord[i]) {
                if (i==0  && ((k!=0 && sentence[k-1] == ' ') || k ==0)) {
                    ++i;
                    flag = true;
                } else if (i!=0) {
                    ++i;
                }
            } else if (flag) {
                i = 0;
            }
            if (i == search_size) return spaces+1; 
        }
        return -1;
    }
};