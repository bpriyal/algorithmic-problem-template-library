class Solution {
    bool util(const string &a,const string &b) {
        int sizea = a.size();
        int sizeb = b.size();
        
        if (sizea > sizeb) {
            int i = 0;
            int j = sizeb-1;
            
            while(j >= 0) {
                if (a[i] != b[j]) {
                    return false;
                } else {
                    ++i;
                    --j;
                }
            }
            j = sizea-1;
            while (i < j) {
                if (a[i] != a[j]) {
                    return false;
                } else {
                    ++i;
                    --j;
                }
            }
        } else if (sizea < sizeb) {
            int i = 0;
            int j = sizeb-1;
            
            while (i < sizea) {
                if (a[i] != b[j]) {
                    return false;
                } else {
                    ++i;
                    --j;
                }
            }
            i = 0;
            
            while (i < j) {
                if (b[i] != b[j]) {
                    return false;
                } else {
                    ++i;
                    --j;
                }
            }
        } else {
            for(int i = 0;i < sizea;++i) {
                if (a[i] != b[sizeb-1-i]) {
                    return false;
                }
            }
        }
        
        return true;
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int size = words.size();
        vector<vector<int>> result;
        
        for(int i = 0;i < size;++i) {
            for(int j = 0;j < size;++j) {
                if (i != j && util(words[i],words[j])) {
                    result.push_back({i,j});
                }
            }
        }
        
        return result;
    }
};