class CombinationIterator {
    string chars;
    int length;
    vector<string> cache;
    int pos;
    void init() {
        for(int i = 0;i<pow(2,chars.size());++i) {
            string s = "";
            int temp = i;
            int pos = 0;
            while(temp != 0) {
                if (s.size() > length) {
                    break;
                }
                if (temp % 2 != 0) {
                    s += chars[pos];
                }
                ++pos;
                temp = temp >> 1;
            }
            if (s.size() == length) {
                cache.push_back(s);
            }
        }
    }
public:
    CombinationIterator(string characters, int combinationLength) {
        chars = characters;
        length = combinationLength;
        pos = 0;
        init();
    }
    
    string next() {
        return cache[pos++];
    }
    
    bool hasNext() {
        return pos < cache.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */