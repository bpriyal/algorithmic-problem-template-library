class Solution {
    unordered_map<char,int> cache;
    
    bool isInOrder(const string &word1,const string &word2) {
        int n1=0,n2=0;
        int size1 = word1.size();
        int size2 = word2.size();
        
        while(n1 < size1 && n2 < size2) {
            if (cache[word1[n1]] < cache[word2[n2]]) {
                return true;
            } else if (cache[word1[n1]] > cache[word2[n2]]) {
                return false;
            }
            ++n1;
            ++n2;
        }
        
        return size1 <= size2;
    }
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int size = words.size();
        for(int k =0;k < 26;++k) {
            cache[order[k]] = k;
        }
        
        for(int i = 0;i < size-1;++i) {
            if(!isInOrder(words[i],words[i+1])) {
                return false;
            }
        }
        
        return true;
    }
};