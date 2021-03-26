class Solution {
    vector<int> counter(const string& vec) {
        vector<int> temp(26,0);
        
        for(char c:vec) {
            ++temp[c-'a'];
        }
        return temp;
    }
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        int sizeA = A.size();
        int sizeB = B.size();
        
        vector<int> filter(26,0);
        vector<int> temp;
        vector<string> result;
        
        for(string &s:B) {
            temp = counter(s);
            for(int i = 0;i < 26;++i) {
                filter[i] = max(filter[i],temp[i]);
            }
        }
        
        for(string &s:A) {
            temp = counter(s);
            int i;
            for(i = 0;i < 26;++i) {
                if (temp[i] < filter[i]) {
                    break;
                }
            }
            if (i == 26) {
                result.push_back(s);
            }
        }
        
        return result;
    }
};