class Solution {
public:
    /*int editDistance(string &word1,string &word2,int r1,int r2) {
        //cout<<word1[r1]<<" "<<word2[r2]<<r1<<" "<<r2<<endl;
        if (r1 == 0) return 0;
        if (r2 == 0) return INT_MAX;
        if (word1[r1] == word2[r2]) {
           return editDistance(word1,word2,r1-1,r2-1);
        } else {
            //insert
            int a = editDistance(word1,word2,r1,r2-1);
            
            //delete
            int b = editDistance(word1,word2,r1-1,r2);
            
            //replace
            int c = editDistance(word1,word2,r1-1,r2-1);
            
            return std::min({a,b,c}) + 1;
        }
    }*/
    
    int minDistance(string word1, string word2) {
        int size1 = word1.size();
        int size2 = word2.size();
        //return editDistance(word1,word2,size1-1,size2-1);
        vector<vector<int>> cache(size1+1);
        for (int i=0;i <= size1;++i) {
            cache[i] = vector<int>(size2+1);
            cache[i][0] = i;
        }
        for (int i =1;i<=size2;++i) {
            cache[0][i] = i;
        }
        for (int i=1;i<=size1;++i) {
            for(int j=1;j<=size2;++j) {
                if (word1[i-1] == word2[j-1]) {
                    cache[i][j] = cache[i-1][j-1];
                } else {
                    cache[i][j] = 1 + std::min({cache[i-1][j],cache[i][j-1],cache[i-1][j-1]});
                }
            }
        }
        return cache[size1][size2];
    }
};