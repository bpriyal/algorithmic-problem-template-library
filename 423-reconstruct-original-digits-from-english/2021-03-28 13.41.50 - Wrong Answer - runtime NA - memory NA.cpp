class Solution {
    vector<int> counter(string s) {
        vector<int> cache(26,0);
        
        for(char c:s) {
            ++cache[c-'a'];
        }
        
        return cache;
    }
public:
    string originalDigits(string s) {
        vector<vector<int>> cache = {counter("zero"),counter("one"),counter("two"),counter("three"),counter("four"),counter("five"),counter("six"),counter("seven"),counter("eight"),counter("nine")};
        
        vector<int> strcounter = counter(s);
        string result = {};
        int count = 0;
        cout<<"here"<<endl;
        for(vector<int> &num:cache) {
            int i = 0;
            for(i = 0;i < 26;++i) {
                if (strcounter[i] < num[i]) {
                    break;
                }
            }
            if (i == 26) {
                result += to_string(count);
                for(int j = 0;j < 26;++j) {
                    strcounter[j] = strcounter[j] - num[j];
                }
            }
            ++count;
        }
        return result;
    }
};