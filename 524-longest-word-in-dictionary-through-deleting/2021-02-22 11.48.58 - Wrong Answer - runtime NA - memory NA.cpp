class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        vector<int> cache(26,0);
        for(char c:s) {
            ++cache[c-'a'];
        }
        
        string result = "";
        int _maxSize = 0;
        
        for(string word:d) {
            //cout<<word<<endl;
            int size = word.size();
            if (size >= _maxSize) {
                int i;
                for(i = 0;i < size;++i) {
                    --cache[word[i]-'a'];
                    if (cache[word[i]-'a'] < 0) {
                        break;
                    }
                }
                
                if(i == size) {
                    //cout<<"here"<<endl;
                    --i;
                    if (size == _maxSize) {
                        if (result > word) {
                            result = word;
                        }
                    } else {
                        _maxSize = size;
                        result = word;
                    }
                }
                for(int j = 0;j <= i;++j) {
                    ++cache[word[j]-'a'];
                }
            }
        }
        return result;
    }
};