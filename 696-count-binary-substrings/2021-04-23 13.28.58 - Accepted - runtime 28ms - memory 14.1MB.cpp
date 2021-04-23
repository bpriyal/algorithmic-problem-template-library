class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> counter;
        
        int count = 1;
        
        for(int i = 1;i < s.size();++i) {
            if (s[i] != s[i-1]) {
                if (count == 0) {
                    ++count;
                } else {
                    counter.push_back(count);
                    count = 0;
                }
            }
            ++count;
        }
        counter.push_back(count);
        
        /*for(int a:counter) {
            cout<<a<<"\t";
        }
        cout<<endl;*/
        int result = 0;
        for(int i = 0;i < counter.size()-1;++i) {
            result += min(counter[i],counter[i+1]);
        }
        return result;
    }
};