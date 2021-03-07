class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int size = words.size();
        int result = words[0].size()+1;
        
        for(int i = 1;i < size;++i) {
            int sizeCurr = words[i].size();
            int sizePrev = words[i-1].size();
            if (sizeCurr <= sizePrev && words[i] == words[i-1].substr(sizePrev-sizeCurr)) {
                continue;
            } else {
                result += sizeCurr + 1;
            }
        }
        return result;
    }
};