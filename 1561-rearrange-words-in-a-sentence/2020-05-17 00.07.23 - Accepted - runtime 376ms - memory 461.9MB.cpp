class Solution {
public:
    string arrangeWords(string text) {
        map<int,string> cache;
        int i;
        string output;
        int first = 0;
        int size = text.size();
        string temp = "";
        for ( i=0;i<size;++i) {
            if (text[i] == ' ') {
                if(cache.find(i-first) != cache.end()) {
                    cache[i-first]=cache[i-first] + " " + temp;
                } else {
                    cache[i-first] = temp;
                }
                if (first == 0) {
                    cache[i-first][0] += 'a'-'A';
                }
                first = i+1;
                temp = "";
            } else {
                temp.push_back(text[i]);
            }
        }
        if(cache.find(i-first) != cache.end()) {
            cache[size-first] = cache[size-first] + " " + temp;
        } else {
            cache[size-first] = temp;
        }
        for (auto it=cache.begin();it!=cache.end();++it) {
            output = output + it->second+ " ";
        }
        output.pop_back();
        output[0] -= 'a'-'A';
        return output;
    }
};